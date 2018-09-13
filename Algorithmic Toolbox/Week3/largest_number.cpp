#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

using std::string;
using std::vector;

//a->digit
//b->max_digit right now
bool isGreaterOrEqual(string a, string b) {
    return (a + b).compare(b + a) > 0 ? true : false;
}

string largest_number(vector<string> a) {
    //  LargestNumber(Digits):
    //  answer ← empty string
    //  while Digits is not empty:
    //      maxDigit ← −∞
    //  for digit in Digits:
    //      if digit ≥ maxDigit:
    //          maxDigit ← digit
    //  append maxDigit to answer
    //  remove maxDigit from Digits
    //  return answer
    //  write your code here
    std::stringstream ret; // output string
    while (!a.empty()) {
        string maxDigit = "-32767";
        int max_index = 0;
        for (size_t i = 0; i < a.size(); i++) {
            if (isGreaterOrEqual(a[i], maxDigit)) {
                maxDigit = a[i];
                max_index = i;
            }
        }
        //append max to answer
        ret << maxDigit;
        //remove max from a
        a.erase(a.begin() + max_index);
    }
    // return result
    string result;
    ret >> result;
    return result;
}

void testSolution() {
    vector<string> a = {"21", "2"};
    string true_ans = "221";
    assert(largest_number(a).compare(true_ans) == 0);
    a = {"21"};
    true_ans = "21";
    assert(largest_number(a).compare(true_ans) == 0);
    a = {"9", "4", "6", "1", "9"};
    true_ans = "99641";
    assert(largest_number(a).compare(true_ans) == 0);
    a = {"23", "39", "92"};
    true_ans = "923923";
    assert(largest_number(a).compare(true_ans) == 0);
    a = {"223", "22", "25"};
    true_ans = "2522322";
    assert(largest_number(a).compare(true_ans) == 0);
    a = {"2221", "22", "25"};
    true_ans = "25222221";
    assert(largest_number(a).compare(true_ans) == 0);
    a = {"2", "8", "2", "3", "6", "4", "1", "1", "10", "6", "3", "3", "6", "1", "3", "8", "4", "6", "1", "10", "8", "4",
         "10", "4", "1", "3", "2", "3", "2", "6", "1", "5", "2", "9", "8", "5", "10", "8", "7", "9", "6", "4", "2", "6",
         "3", "8", "8", "9", "8", "2", "9", "10", "3", "10", "7", "5", "7", "1", "7", "5", "1", "4", "7", "6", "1",
         "10", "5", "4", "8", "4", "2", "7", "8", "1", "1", "7", "4", "1", "1", "9", "8", "6", "5", "9", "9", "3", "7",
         "6", "3", "10", "8", "10", "7", "2", "5", "1", "1", "9", "9", "5"};
    true_ans = "9999999998888888888887777777776666666666555555554444444443333333333222222222111111111111111101010101010101010";
    assert(largest_number(a).compare(true_ans) == 0);

    a = {"1", "1", "10", "1", "1", "10", "10", "1", "1", "10", "10", "10", "1", "1", "1", "10", "1", "1", "1", "1",
         "10", "10", "1", "1"};
    true_ans = "111111111111111101010101010101010";
    assert(largest_number(a).compare(true_ans) == 0);
}

int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
    //testSolution();
}
