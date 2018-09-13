#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>

int pisano_length(int m, std::vector<long long> &vecs) {
    vecs.push_back(0);
    vecs.push_back(1);
    int i = 0;
    long long current;
    while (true) {
        if (vecs[vecs.size() - 1] == 0 && vecs[vecs.size() - 2] == 1 && i != 0) {
            break;
        }
        current = (vecs[vecs.size() - 1] + vecs[vecs.size() - 2]) % m;
        vecs.push_back(current);
        i++;
    }
    return i + 1;
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    std::vector<long long> vecs;
    int pisano_len = pisano_length(m, vecs);
    int actual_fib = n % pisano_len;
    return vecs[actual_fib];
}

void testSolution() {
    assert(get_fibonacci_huge_fast(1, 239) == 1);
    assert(get_fibonacci_huge_fast(239, 1000) == 161);
    assert(get_fibonacci_huge_fast(2816213588, 30524) == 10249);
    std::cout << "Passed\n";
    while (true) {
        long long n = rand() % 10000000 + 2;
        long long m = rand() % 100000 + 2;
        std::cout << "n = " << n << " ,m = " << m << '\n';
        int result1 = get_fibonacci_huge_fast(m, n);
        int result2 = get_fibonacci_huge_naive(m, n);
        std::cout << "fast = " << result1 << " ,naive = " << result2 << '\n';
        assert(result1 == result2);
        std::cout << "Passed\n";
    }
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    //testSolution();
}
