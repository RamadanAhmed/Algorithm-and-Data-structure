#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <iomanip>      // std::setprecision
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int vec_size = weights.size();
  // write your code here
  while (capacity != 0){
    int bestItem = -1;
    double bestValPerWeight = -1;
    for (int i = 0; i < vec_size; i++)
    {
      if ((weights[i] != 0) && ((double)values[i]/weights[i] > bestValPerWeight)){
        bestItem = i;
        bestValPerWeight = (double)values[i]/weights[i];
      }
    }
    if (bestItem == -1){
      break;
    }
    else if(weights[bestItem] >= capacity) {
      value += ((double)values[bestItem]/weights[bestItem]) * capacity;
      break;
    }
    else {
      value += (double) values[bestItem];
      capacity -= weights[bestItem];
      weights[bestItem] = 0;
    }
  }
  return value;
}

void testSolution(){
  std::setprecision(4);
  {
    // 3 50
    // 60 20
    // 100 50
    // 120 30
    vector<int> weights = {20,50,30};
    vector<int> values = {60,100,120};
    assert(get_optimal_value(50,weights,values)==180.0000);
    std::cout << "Passed" << '\n'; 
  }
  {
    // 1 10
    // 500 30
    vector<int> weights = {30};
    vector<int> values = {500};
    assert(get_optimal_value(10,weights,values)==166.6667);
    std::cout << "Passed" << '\n'; 
  }
  
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  //testSolution();
  return 0;
}
