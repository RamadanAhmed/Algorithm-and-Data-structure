#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

// add 3-way partition to solve quick sort problem
void partition3(vector<int> &a, int low, int high, int &midLow, int &midHigh) {
    int pivot = a[low];
    midLow = low, midHigh = high;
    int i = low + 1;
    while (i <= midHigh) {
        // every thing larger than the pivot goes right
        if (pivot < a[i])
            swap(a[i], a[midHigh--]);
            // every thing smaller than the pivot goes left
        else if (pivot > a[i])
            swap(a[i++], a[midLow++]);

        else i++;
    }

}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int midLow, midHigh;
    partition3(a, l, r, midLow, midHigh);

    randomized_quick_sort(a, l, midLow - 1);
    randomized_quick_sort(a, midHigh + 1, r);
}

void testSolution() {

    vector<int> vec = {2, 3, 9, 2, 2};
    vector<int> ans = {2, 2, 2, 3, 9};
    randomized_quick_sort(vec, 0, (vec.size() - 1));
    for (int i : vec) {
        std::cout << i << ' ';
    }
    // check if array is sorted
    for (int i = 0; i < vec.size(); i++)
        assert(vec[i] == ans[i]);

}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (int &i : a) {
        std::cin >> i;
    }
    randomized_quick_sort(a, 0, static_cast<int>(a.size() - 1));
    for (int i : a) {
        std::cout << i << ' ';
    }
//    testSolution();
}
