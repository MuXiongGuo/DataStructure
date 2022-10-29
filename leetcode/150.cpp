#include "string"
#include "stack"
#include "vector"
#include "iostream"

using namespace std;



// 注意代码复用问题  每次都要 取两个数  那么不如 直接取 再 switch
// 中间溢出  longlong 转 int  如果 没超过 int  则一定转 成功  本质 是补码  负数 也一样  顺便  int 的负数比正数多一
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<long long> st;
        for (const auto &a: tokens) {
            if (a == "+") {
                long long tem = st.top();
                st.pop();
                tem += st.top();
                st.pop();
                st.push(tem);
            } else if (a == "-") {
                long long tem = st.top();
                st.pop();
                tem = st.top() - tem;
                st.pop();
                st.push(tem);
            } else if (a == "*") {
                long long tem = st.top();
                st.pop();
                tem *= st.top();
                st.pop();
                st.push(tem);
            } else if (a == "/") {
                long long tem = st.top();
                st.pop();
                tem = st.top() / tem;
                st.pop();
                st.push(tem);
            } else {
                st.push(stoi(a));
            }
        }
        return st.top();
    }
};

int main() {
    Solution s;
    vector<string> v = {"-128","-128","*","-128","*","-128","*","8","*","-1","*"};
    cout << s.evalRPN(v) << endl;

    return 0;
}