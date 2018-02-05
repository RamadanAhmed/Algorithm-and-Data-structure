#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

#include <cstdlib>
#include <cassert>

using std::vector;

bool myfunction (int i,int j) { return (i<j); }

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  std::sort (a.begin(), a.end(), myfunction);
  std::sort (b.begin(), b.end(), myfunction);
  
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

void testSolution(){
  {
    // 1
    // 23
    // 39
    vector<int> weights = {23};
    vector<int> values = {39};
    assert(max_dot_product(weights,values)==897);
    std::cout << "Passed" << '\n'; 
  }
  {
    // 3
    // 1 3 -5
    // -2 4 1
    vector<int> weights = {1,3,-5};
    vector<int> values = {-2,4,1};
    assert(max_dot_product(weights,values)==23);
    std::cout << "Passed" << '\n'; 
  }
  
}
int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
  //testSolution();
  //return 0;
}
