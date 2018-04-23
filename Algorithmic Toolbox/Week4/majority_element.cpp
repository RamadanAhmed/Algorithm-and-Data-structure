#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];
    //write your code here
    std::sort(a.begin(), a.end());
    int current_lookup = -1, lookup_counter = 0;
    int found = -1;
    for (int i : a) {
        if (current_lookup != i) {
            current_lookup = i;
            lookup_counter = 1;
        } else lookup_counter++;

        if (lookup_counter > (a.size() / 2)) {
            found = 1;
            break;
        }
    }

    return found;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
