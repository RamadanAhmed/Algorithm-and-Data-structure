#include <iostream>
#include <cstdlib>
#include <cassert>

int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}

int gcd_fast(int a, int b) {
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    int remainder = a % b;
    return gcd_fast(b, remainder);
}

void testSolution() {
    assert(gcd_fast(18, 35) == 1);
    assert(gcd_fast(28851538, 1183019) == 17657);
    while (true) {
        int a = rand() % 10 + 2;
        int b = rand() % 10 + 2;
        std::cout << "a = " << a << ",b = " << b << '\n';
        assert(gcd_fast(a, b) == gcd_naive(a, b));
        std::cout << "Passed\n";
    }
}

int main() {
    int a, b;
    //testSolution();
    std::cin >> a >> b;
    std::cout << gcd_fast(a, b) << std::endl;
    return 0;
}