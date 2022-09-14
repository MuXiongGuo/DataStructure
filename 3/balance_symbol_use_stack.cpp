//
// Created by dell on 2022/9/14.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<char> char_stack;
    string input_str;
    cin >> input_str;
    string bracket = "({[]})";
    for (auto &i: input_str) {
        if (bracket.find(i) != string::npos) {
            if (i == '(' || i == '{' || i == '[') {
                char_stack.push_back(i);
            } else {
                // 防止对空栈进行pop操作
                if (char_stack.empty()) {
                    cout << "false";
                    return 0;
                }
                char top = char_stack.back();
                char_stack.pop_back();
                if (i == ')' && top != '(') {
                    cout << "false";
                    return 0;
                }
                if (i == '}' && top != '{') {
                    cout << "false";
                    return 0;
                }
                if (i == ']' && top != '[') {
                    cout << "false";
                    return 0;
                }
            }
        }
    }
    if (char_stack.empty()) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}
