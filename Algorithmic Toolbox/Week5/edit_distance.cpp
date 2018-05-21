#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using std::string;

int min_3_number(int x, int y, int z) {
    if (x < y && x < z)
        return x;
    else if (y < z && y < x)
        return y;
    else
        return z;
}

int edit_distance(const string &str1, const string &str2) {
    std::vector<std::vector<int>> distance;
    for (int i = 0; i <= str1.size(); i++) {
        std::vector<int> row(str2.size() + 1, 0);
        distance.push_back(row);
    }
    for (unsigned int j = 0; j <= str2.size(); j++) {
        distance.at(0).at(j) = j;
    }
    for (unsigned int i = 0; i < str1.size(); i++) {
        distance.at(i).at(0) = i;
    }
    for (unsigned int j = 1; j <= str2.size(); j++) {
        for (unsigned int i = 1; i <= str1.size(); i++) {
            int insertion = distance.at(i).at(j - 1) + 1;
            int deletion = distance.at(i - 1).at(j) + 1;
            int mismatch = distance.at(i - 1).at(j - 1) + 1;
            int match = distance.at(i - 1).at(j - 1);
            if (str1[i - 1] == str2[j - 1])
                distance.at(i).at(j) = min_3_number(insertion, deletion, match);
            else
                distance.at(i).at(j) = min_3_number(insertion, deletion, mismatch);
        }
    }
    return distance.at(str1.size()).at(str2.size());
}

void TestSolution() {
    assert(edit_distance("ab", "ab") == 0);
    assert(edit_distance("short", "ports") == 3);
    assert(edit_distance("editing", "distance") == 5);
}

int main() {
    string str1;
    string str2;
//    TestSolution();
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
