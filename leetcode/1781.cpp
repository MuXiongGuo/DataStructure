#include "bits/stdc++.h"

using namespace std;

// 暴力 循环  复杂度 n^2 * C C为哈希表最大长度26
class Solution {
public:
    int beautySum(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> lookup;
            for (int j = i; j < n; ++j) {
                ++lookup[s[j]];
                int max_el = INT_MIN, min_el = INT_MAX;
                for (const auto &el:lookup) {
                    max_el = max(max_el, el.second);
                    min_el = min(min_el, el.second);
                }
                res += max_el-min_el;
            }
        }

        return res;
    }
};

// 官方聪明一些 知道最大的Freq一定义当前才加入的那个
class Solution2 {
public:
    int beautySum(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> cnt(26);
            int maxFreq = 0;
            for (int j = i; j < s.size(); j++) {
                cnt[s[j] - 'a']++;
                maxFreq = max(maxFreq, cnt[s[j] - 'a']);
                int minFreq = s.size();
                for (int k = 0; k < 26; k++) {
                    if (cnt[k] > 0) {
                        minFreq = min(minFreq, cnt[k]);
                    }
                }
                res += maxFreq - minFreq;
            }
        }
        return res;
    }
};
