#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>

using std::vector;

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

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = (next + current) % 10;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long m, long long n) {
    int sum_of_elems = 0;
    std::vector<long long> vecs;
    int pisano_len = pisano_length(10, vecs);
    int actual_fib = n % pisano_len;
    int actual_start = m % pisano_len;
    for (int i = actual_start; i < actual_fib + 1; i++) {
        sum_of_elems += vecs[i];
    }
    return sum_of_elems % 10;
}

void testSolution() {
    assert(get_fibonacci_partial_sum_fast(3, 7) == 1);
    assert(get_fibonacci_partial_sum_fast(10, 10) == 5);
    assert(get_fibonacci_partial_sum_fast(10, 200) == 2);
    assert(get_fibonacci_partial_sum_fast(1234, 12345) == 8);
    std::cout << "Passed\n";
    while (true) {
        long long n = rand() % 10000000 + 2;
        long long m = rand() % 100000 + 2;
        std::cout << "n = " << n << " ,m = " << m << '\n';
        int result1 = get_fibonacci_partial_sum_fast(m, n);
        int result2 = get_fibonacci_partial_sum_naive(m, n);
        std::cout << "fast = " << result1 << " ,naive = " << result2 << '\n';
        assert(result1 == result2);
        std::cout << "Passed\n";
    }
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
    //testSolution();
}