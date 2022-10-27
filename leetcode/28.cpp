#include "string"
#include "iostream"

using namespace std;

// 暴力枚举
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
            return -1;
        int left;
        for (int i = 0; i < haystack.size(); ++i) {
           if (haystack[i] == needle[0]) {
               int index = 0;
               left = i;
               int tem = i;
               while (tem < haystack.size() && index < needle.size() && haystack[tem] == needle[index]) ++tem, ++index;
               if (index == needle.size())
                   return left;
           }
        }
        return -1;
    }
};

// KMP算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};
//
//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/solution/shi-xian-strstr-by-leetcode-solution-ds6y/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


int main() {
    Solution s;
    cout << s.strStr("mississippi", "issip") << endl;
    return 0;
}