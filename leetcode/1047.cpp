#include "stack"
#include "string"
#include "algorithm"

using namespace std;

// 转换时  要用 reverse + += 这样更快
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans;
        for (const auto &a: s) {
            if (!st.empty() && st.top() == a) st.pop();
            else
                st.push(a);
        }
        while (!st.empty()) {
            ans += st.top(); // top() 有可能溢出  毕竟栈深度有限  所以有提示
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 直接拿string当作栈  聪明
class Solution2 {
public:
    string removeDuplicates(string S) {
        string result;
        for(char s : S) {
            if(result.empty() || result.back() != s) {
                result.push_back(s);
            }
            else {
                result.pop_back();
            }
        }
        return result;
    }
};