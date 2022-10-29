#include "string"
#include "iostream"

using namespace std;

// find 1  以及 !+s.size()  表示了 去掉头部尾部的结果
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};

// 暴力匹配  优化版  只取前1/2  且每次只看倍数的  且每次i, j 关系来匹配, 不用 i j 同时 +-
class Solution2 {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1)
            return false;
        for (int i = 1; i < s.size(); ++i) {
            if (s.size() % i == 0) {
                bool match = true;
                for (int j = i; j < s.size(); ++j) {
                    if (s[j] != s[j - i]) {
                        match = false;
                        break;
                    }
                }
                if (match)
                    return true;
            }
        }
        return false;
    }
};

// KMP
class Solution3 {
public:
    void getNext(int *next, string s) {
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j])
                j = next[j-1];
            if (s[i] == s[j])
                ++j;
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int next[n];
        getNext(next, s);
        if (next[n-1] != 0 && n % (n - next[n-1]) == 0)
            return true;
        else
            return false;
    }
};
