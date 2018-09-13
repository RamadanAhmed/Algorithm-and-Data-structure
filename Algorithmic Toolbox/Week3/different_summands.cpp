#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    //write your code here
    int i = 1;
    while (n != 0) {
        if (!std::binary_search(summands.begin(), summands.end(), n - i) && (n - i != i)) {
            summands.push_back(i);
            n -= i;
        }
        i++;
    }
    return summands;
}

void testSolution() {
    vector<int> numbers = optimal_summands(6);
    vector<int> true_numbers = {1, 2, 3};
    assert(numbers == true_numbers);
    std::cout << "Passed :D\n";
    true_numbers = {1, 2, 5};
    numbers = optimal_summands(8);
    assert(numbers == true_numbers);
    std::cout << "Passed :D\n";
    true_numbers = {2};
    numbers = optimal_summands(2);
    assert(numbers == true_numbers);
    std::cout << "Passed :D\n";
    true_numbers = {1, 2, 3, 4, 5, 7};
    numbers = optimal_summands(22);
    assert(numbers == true_numbers);
    std::cout << "Passed :D\n";
    true_numbers = {1};
    numbers = optimal_summands(1);
    assert(numbers == true_numbers);
    std::cout << "Passed :D\n";
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
    //testSolution();
}
