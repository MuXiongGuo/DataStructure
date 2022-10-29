#include "iostream"
#include "string"

using namespace std;


class Solution {
public:
    void getNext(int* next, const string& s){
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            // 0. special condition
            if (i == 0) {
                next[i] = 0;
                continue;
            }
            // 1. != condition
            while (j>0 && s[i] != s[j]) j = next[j-1];
            // 2. == condition
            if (s[i] == s[j])
                ++j;
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        int next[needle.size()];
        getNext(next, needle);
        // use j on behalf of pointer of needle
        int j = 0;
        for (int  i = 0;  i < haystack.size(); ++ i) {
            while (j > 0 && haystack[i] != needle[j]) j = next[j-1];
            if (haystack[i] == needle[j]) ++j;
            if (j == needle.size())
                return i - j + 1;
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.strStr("leetcode", "leeto") << endl;
    cout << s.strStr("aaaaa", "bba") << endl;
    cout << s.strStr("mississippi", "issip") << endl;


    return 0;
}