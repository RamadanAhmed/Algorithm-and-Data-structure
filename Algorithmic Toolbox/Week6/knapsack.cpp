#include <iostream>
#include <vector>

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
    return 0;
}

int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
