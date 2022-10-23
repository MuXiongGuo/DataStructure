#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    unordered_map<char, int> ori, cnt;

    bool checkMap() {
        for (const auto &a: ori) {
            if (cnt[a.first] != a.second)
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        for (const auto a: p)
            ++ori[a];
        int slow = 0, fast = 0;
        for (; fast < s.size(); ++fast) {
            if (ori.find(s[fast]) != ori.end())
                ++cnt[s[fast]];
            else {
                slow = fast+1;
                cnt.clear();
                continue;
            }
            // 判断相等之前 先判断元素数量是不是超了
            if (cnt[s[fast]] > ori[s[fast]]) {
                while (cnt[s[fast]] > ori[s[fast]])
                    --cnt[s[slow++]];
                continue;
            }

            if (checkMap()) {
                ans.emplace_back(slow);
                --cnt[s[slow++]];
            }

        }
        return ans;
    }
};


// 官方喜欢用 vector 作为哈希表
class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        if (sCount == pCount) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pLen] - 'a'];

            if (sCount == pCount) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};

// 要学会灵活变通，本质上是另一种滑动窗口 与 76 不同
// 76 是右边先走，直到达成，再移动左边，这次是同时移动，且 vector 作为哈希表，以及利用 differ
// 这两个的时间复杂度也是一绝，空间显然为 o(26)
// solution2 为 o(m + (n-m)*26) solution3 为 o(m + n + 26)  可以看官方解析
// 自己的写法 大材小用了  毕竟窗口大小固定不变的（所以每次左右同时移动并且判断） 优化版 只考虑字母差 differ 更是聪明
class Solution3 {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> count(26);
        for (int i = 0; i < pLen; ++i) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }

        int differ = 0;
        for (int j = 0; j < 26; ++j) {
            if (count[j] != 0) {
                ++differ;
            }
        }

        if (differ == 0) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
            if (count[s[i] - 'a'] == 1) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从不同变得相同
                --differ;
            } else if (count[s[i] - 'a'] == 0) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从相同变得不同
                ++differ;
            }
            --count[s[i] - 'a'];

            if (count[s[i + pLen] - 'a'] == -1) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从不同变得相同
                --differ;
            } else if (count[s[i + pLen] - 'a'] == 0) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从相同变得不同
                ++differ;
            }
            ++count[s[i + pLen] - 'a'];

            if (differ == 0) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};

