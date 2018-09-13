#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

std::pair<long long, long long>
MinMax(long long i, long long j, const vector<char> &op, const vector<vector<long long>> &M, const vector<vector<long long>> &m) {
    long long mmax =LONG_LONG_MIN;
    long long mmin =LONG_LONG_MAX;
    for (long long k = i; k < j; k++){
        long long a = eval(M[i][k],M[k+1][j],op[k]);
        long long b = eval(M[i][k],m[k+1][j],op[k]);
        long long c = eval(m[i][k],M[k+1][j],op[k]);
        long long d = eval(m[i][k],m[k+1][j],op[k]);
        mmax = std::max(mmax,std::max(std::max(a,b),std::max(c,d)));
        mmin = std::min(mmin,std::min(std::min(a,b),std::min(c,d)));
    }
    return std::make_pair(mmin,mmax);
}

long long get_maximum_value(const string &exp) {
    std::vector<char> op;
    std::vector<int> digit;
    for (int i = 0; i < exp.size(); i++) {
        if (i % 2 == 1)
            op.emplace_back(exp[i]);
        else
            digit.emplace_back(exp[i] - '0');
    }
    unsigned long n = digit.size();
    vector<long long> init(n, 0);
    vector<vector<long long>> M(n, init);
    vector<vector<long long>> m(n, init);
    for (int i = 0; i < n; i++)
        M[i][i] = m[i][i] = digit[i];

    for (int s = 1; s < n; s++) {
        for (int i = 0; i < n - s; i++) {
            long long j = i + s;
            auto min_max_pair = MinMax(i, j, op, M, m);
            m[i][j] = min_max_pair.first;
            M[i][j] = min_max_pair.second;
        }
    }
    return M[0][n-1];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
