#include "string"
#include "iostream"

using namespace std;

// O(n)空间 栈
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s_stack, t_stack;
        for (const auto &a: s) {
            if (a == '#' && !s_stack.empty())
                s_stack.pop_back();
            else if (a != '#')
                s_stack.push_back(a);
        }
        for (const auto &a: t) {
            if (a == '#' && !t_stack.empty())
                t_stack.pop_back();
            else if (a != '#')
                t_stack.push_back(a);
        }
        return s_stack == t_stack;
    }
};

// O(1)空间  双指针  本质上只要求判断出来就可以，可以不用更改元素，聪明！！！
class Solution2 {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int i_skip = 0, j_skip = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0){
                if (s[i] == '#')
                    ++i_skip, --i;
                else if (i_skip != 0)
                    --i_skip, --i;
                else
                    break;
            }
            while (j >= 0){
                if (t[j] == '#')
                    ++j_skip, --j;
                else if (j_skip != 0)
                    --j_skip, --j;
                else
                    break;
            }
            if (i >=0 && j >= 0) {
                if (s[i] != t[j])
                    return false;
            } else {
                if (i >= 0 || j >= 0)
                    return false;
            }
            --i, --j;
        }
        return true;
    }
};


int main() {
    Solution2 s;
    string s1 = "ab#c", t1 = "ad#c";
    bool res = s.backspaceCompare(s1, t1);
    cout << res;
    return 0;
}