#include <iostream>
#include <cstdlib>
#include <cassert>

int get_change(int m) {
  //write your code here
  int min_coins = 0;
  while (m != 0)
  {
    if (m / 10 != 0){
      min_coins += (int) m / 10;
      m %= 10;
    }
       
    else if (m / 5 != 0){
      min_coins += (int) m / 5;
      m %= 5;
    }
    else{
      min_coins += 1;
      m--;
    }
      
  }
  return min_coins;
}
void testSolution(){
  std::cout << "Change ="<< get_change(2) << '\n';
  assert(get_change(2) == 2);
  std::cout << "Change ="<< get_change(28) << '\n';
  assert(get_change(28) == 6);
  std::cout << "Passed\n";
}
int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
  //testSolution();
}
