#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <cmath>
#include <cstdlib>
using std::vector;

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int) a.size() - 1;
    //write your code here
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (x == a[mid])
            return mid;
            // search in left part of the array
        else if (x < a[mid])
            right = mid - 1;
            // search right part of the array
        else
            left = mid + 1;
    }
    return -1;
}

int linear_search(const vector<int> &a, int x) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

void TestSolution() {
    while (true) {
        vector<int> a;
        int arr_size = rand() % 1000 + 1;
        for (int i = 0; i < arr_size; ++i) {
            a.push_back(rand() % 100000);
        }
        std::cout << "Array: ";
        //print the array
        for (int i = 0; i < arr_size; ++i) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
        // random select an element to search
        int randomIndex = rand() % 100000;
        std::cout << "Search Number : " << randomIndex << '\n';
        std::sort(a.begin(), a.end());
        //function that easy to compute ("Brute Force Solution")
        long long res1 = linear_search(a, randomIndex);
        //function that you try to test its correctness
        long long res2 = binary_search(a, randomIndex);
        if (res1 != res2) {
            std::cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        } else {
            std::cout << "OK\n";
        }
    }
}
int main() {
    unsigned int n;
    std::cin >> n;
    vector<int> a(n);
    for (int &i : a) {
        std::cin >> i;
    }
    unsigned int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        //replace with the call to binary_search when implemented
        std::cout << binary_search(a, b[i]) << ' ';
    }
//    TestSolution();
}
