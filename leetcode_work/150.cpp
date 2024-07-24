#include <stack>
#include <string>

#include "vector"
using namespace std;

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        long long x, y;
        for (const auto& el : tokens) {
            if (el == "+") {
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(x + y);
            } else if (el == "-") {
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(y - x);
            } else if (el == "*") {
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(y * x);
            } else if (el == "/") {
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                st.push(y / x);
            } else {
                st.push(stoi(el));
            }
        }


        return st.top();
    }
};

// 官方解答 更加简洁
class Solution2 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            string& token = tokens[i];
            if (isNumber(token)) {
                stk.push(atoi(token.c_str()));
            } else {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch (token[0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
        }
        return stk.top();
    }

    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};
