#include "string"
#include "stack"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (const auto a: s) {
            if (a == '(' || a == '[' || a == '{')
                st.push(a);
            else if (a == ')') {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
            } else if (a == ']') {
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else
                    return false;
            } else if (a == '}') {
                if (!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};