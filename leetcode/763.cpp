#include "bits/stdc++.h"

using namespace std;

// 思想很简单  难点在于头部 尾部特殊情况
// 难点在于 出现单个的时候 此时要先更新再判断
// 还有一点  字母哈希表 要想到用int数组来做  比如 int a[26]  a[s[i] - 'a'] = i 这种格式
// 毕竟只有26个字母
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> str_max_index;
        // 得到 每个单词的最大范围
        for (int i = 0; i < s.size(); ++i) {
            str_max_index[s[i]] = i;
        }
        int str_size = 0, right_max = str_max_index[s[0]];
        for (int i = 0; i < s.size(); ++i) {
            if (i > right_max) {
                right_max = str_max_index[s[i]];
            }
            if (i == right_max) {
                res.emplace_back(++str_size);
                str_size = 0;
            }
            else {
                right_max = max(right_max, str_max_index[s[i]]);
                ++str_size;
            }
        }
        return res;
    }
};

// 官方这个快 并且明显不用考虑特殊情况
// 值得学习   思想是先更新 然后看符合条件吗
class Solution2 {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        int length = s.size();
        for (int i = 0; i < length; i++) {
            last[s[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};
//
//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/partition-labels/solution/hua-fen-zi-mu-qu-jian-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

