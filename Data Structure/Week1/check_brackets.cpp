#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <iomanip>
#include <cassert>
struct Bracket {
    Bracket(char type, int position) :
            type(type),
            position(position) {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};


std::string checkBracket(const std::string &text) {
    int invalidIndex = -1;
    std::stack<Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket bracket(next, position);
            opening_brackets_stack.push(bracket);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (!opening_brackets_stack.empty() && opening_brackets_stack.top().Matchc(next)) {
                opening_brackets_stack.pop();
            } else {
                invalidIndex = position + 1;
                break;
            }
        }
    }
    // Printing answer, write your code here
    if (invalidIndex > 0) {
        return std::to_string(invalidIndex);
    } else if (!opening_brackets_stack.empty()) {
        return std::to_string(opening_brackets_stack.top().position + 1);
    } else {
        return "Success";
    }
}


void testSolution() {
    for (int i = 1; i < 55; i++) {
        std::ostringstream testName;
        testName << "../tests_check_brackets/" << std::setfill('0') << std::setw(2) << i;
        std::ifstream testFile(testName.str());
        std::cout << testName.str() << std::endl;
        std::ostringstream ansName;
        ansName << "../tests_check_brackets/" << std::setfill('0') << std::setw(2) << i << ".a";
        std::cout << ansName.str() << std::endl;
        std::ifstream AnsFile(ansName.str());
        std::string text;
        getline(testFile,text);
        std::string ans;
        getline(AnsFile,ans);
        assert(checkBracket(text) == ans);
        std::cout << "Passed Test " << i << std::endl;
    }

}

int main() {
    std::string text;
    getline(std::cin, text);
    std::cout << checkBracket(text);
    //testSolution();
    return 0;
}
