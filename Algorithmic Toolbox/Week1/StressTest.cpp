#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long BruteForceSol(const vector<int>& numbers) {
    return 0;
}

long long EfficientSol(const vector<int>& numbers) {
    return 0;
}

int main() {
    while (true) {
        // size of the input ("random number (2,11)")
        int n = rand() % 10 + 2;
        cout << n << "\n";
        vector<int> a;
        // fill the array ("random number (0,99999)")
        for (int i = 0; i < n; ++i) {
            a.push_back(rand() % 100000);
        }
        //print the array
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << "\n";
        //function that easy to compute ("Brute Force Solution")
        long long res1 = BruteForceSol(a);
        //function that you try to test its correctness
        long long res2 = EfficientSol(a);
        if (res1 != res2) {
            cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else {
            cout << "OK\n";
        }
    }
}