#include <iostream>
#include <vector>
#include <climits>
#include <cassert>

using std::vector;

int get_change(int money, vector<int> &MinCoins, const vector<int> &Denominations) {
    MinCoins[0] = 0;
    for (int i = 1; i <= money; ++i) {
        for (auto coin : Denominations) {
            if (i >= coin) {
                int NumCoins = MinCoins[i - coin] + 1;
                if (NumCoins < MinCoins[i]) {
                    MinCoins[i] = NumCoins;
                }
            }
        }
    }
    return MinCoins[money];
}

void TestSolution() {
    vector<int> g_Denominations = {1, 3, 4};
    {
        vector<int> g_MinNumCoins(2 + 1, INT_MAX);
        assert(get_change(2, g_MinNumCoins, g_Denominations) == 2);
    }
    {
        vector<int> g_MinNumCoins(34 + 1, INT_MAX);
        assert(get_change(34, g_MinNumCoins, g_Denominations) == 9);
    }
    {
        vector<int> g_MinNumCoins(6 + 1, INT_MAX);
        assert(get_change(6, g_MinNumCoins, g_Denominations) == 2);
    }
}

int main() {
    // coin denomination is 1, 3, 4
    vector<int> g_Denominations = {1, 3, 4};
    int m;
    std::cin >> m;
    vector<int> g_MinNumCoins(m + 1,INT_MAX);
    std::cout << get_change(m, g_MinNumCoins, g_Denominations) << '\n';
    // TestSolution();
}
