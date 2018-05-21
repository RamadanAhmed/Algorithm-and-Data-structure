#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

std::vector<int> optimal_sequence(int n) {
    std::vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

// possible operations are : multiply by 2, multiply by 3, add 1
std::vector<int> dp_sequence(int n, std::vector<std::pair<int, int>> &MinOps) {
    MinOps.insert(MinOps.begin() + 1, std::make_pair(0, 0));
    std::vector<int> sequence;
    for (int i = 2; i <= n; i++) {
        int div3 = (i % 3 == 0) ? i / 3 : (int) MinOps.size() - 1;
        int div2 = (i % 2 == 0) ? i / 2 : (int) MinOps.size() - 1;
        int add1 = (i - 1 >= 1) ? i - 1 : (int) MinOps.size() - 1;
        // if div3 is smallest
        if (MinOps[div3] <= MinOps[div2] && MinOps[div3] <= MinOps[add1] && MinOps[div3] <= MinOps[i]) {
            MinOps.insert(MinOps.begin() + i, std::make_pair(MinOps[div3].first + 1, div3));
        }
            // if div2 is smallest
        else if (MinOps[div2] <= MinOps[div3] && MinOps[div2] <= MinOps[add1] && MinOps[div2] <= MinOps[i]) {
            MinOps.insert(MinOps.begin() + i, std::make_pair(MinOps[div2].first + 1, div2));
        }
            // if add1 is smallest
        else {
            MinOps.insert(MinOps.begin() + i, std::make_pair(MinOps[add1].first + 1, add1));
        }
    }
    int prev_seq = MinOps[n].second;
    sequence.push_back(n);
    while (prev_seq != 0) {
        sequence.push_back(prev_seq);
        prev_seq = MinOps[prev_seq].second;
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> MinOps((unsigned int) n + 1, std::make_pair(INT_MAX, INT_MAX));
    std::vector<int> sequence = dp_sequence(n, MinOps);

    std::cout << sequence.size() - 1 << std::endl;
    for (int i : sequence)
        std::cout << i << " ";

}
