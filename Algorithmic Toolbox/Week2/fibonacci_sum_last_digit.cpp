#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>

int pisano_length(int m, std::vector<long long> &vecs)
{
    vecs.push_back(0);
    vecs.push_back(1);
    int i = 0;
    long long current;
    while (true)
    {
        if (vecs[vecs.size() - 1] == 0 && vecs[vecs.size() - 2] == 1 && i != 0)
        {
            break;
        }
        current = (vecs[vecs.size() - 1] + vecs[vecs.size() - 2]) % m;
        vecs.push_back(current);
        i++;
    }
    return i + 1;
}

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n)
{
    int sum_of_elems = 0;
    std::vector<long long> vecs;
    int pisano_len = pisano_length(10, vecs);
    int actual_fib = n % pisano_len;
    for (int i = 0; i < actual_fib + 1; i++)
    {
        sum_of_elems += vecs[i];
    }
    return sum_of_elems % 10;
}

void testSolution()
{
    assert(fibonacci_sum_fast(3) == 4);
    assert(fibonacci_sum_fast(100) == 5);
    std::cout << "Passed\n";
    while (true)
    {
        long long n = rand() % 10000000 + 2;
        std::cout << "n = " << n << '\n';
        int result1 = fibonacci_sum_fast(n);
        int result2 = fibonacci_sum_naive(n);
        std::cout << "fast = " << result1 << " ,naive = " << result2 << '\n';
        assert(result1 == result2);
        std::cout << "Passed\n";
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
    //testSolution();
}
