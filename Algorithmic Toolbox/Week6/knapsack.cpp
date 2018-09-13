#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
    //write your code here
    int current_weight = 0;
    for (int i : w) {
        if (current_weight + i <= W) {
            current_weight += i;
        }
    }
    return current_weight;
}

int optimal_weight_dp(int W, const vector<int> &w) {
    std::vector<int> init(W + 1, 0);
    std::vector<std::vector<int>> values(w.size(), init);
    for (int i = 1; i < W + 1; i++) {
        for (int j = 1; j < w.size(); j++) {
            values[j][i] = values[j - 1][i];
            if (w[j - 1] <= i) {
                int candidate = w[j - 1] + values[j - 1][i - w[j - 1]];
                if (candidate > values[j][i]) {
                    values[j][i] = candidate;
                }
            }
        }
    }
    return values[w.size()][W];
}

int main() {
    int W;
    unsigned long n;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight_dp(W, w) << '\n';
}
