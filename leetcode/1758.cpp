#include "bits/stdc++.h"

using namespace std;

// 分别记录 每段不同的长度
// 再间隔2累加即可
class Solution {
public:
    int minOperations(string s) {
        vector<int> length_vec;
        int start = 0;
        for (int i = 1; i <= s.size(); ++i) {
            if (i == s.size()) {
                length_vec.emplace_back(i - start);
                break;
            }
            if (s[i] == s[i - 1]) {
                length_vec.emplace_back(i - start);
                start = i;
            }
        }
        int res1 = 0, res2 = 0;
        for (int i = 0; i < length_vec.size(); i += 2) {
            res1 += length_vec[i];
        }
        for (int i = 1; i < length_vec.size(); i += 2) {
            res2 += length_vec[i];
        }
        return min(res1, res2);

    }
};

// 官方答案 更聪明
// 俯瞰整个字符串 最后的 结果 无非是以0 或 1开头
// 开头统计一遍以0的  再用size减掉就是 1的
// 取最小即可
class Solution2 {
public:
    int minOperations(string s) {
       int res = 0;
       for (int i = 0; i < s.size(); ++i) {
           if (s[i] != ('0'+i%2)) {
               ++res;
           }
       }
        return min(res, int(s.size())-res);
    }
};

int main() {
    Solution sol;
    cout << sol.minOperations("10111") << endl;
    return 0;
}