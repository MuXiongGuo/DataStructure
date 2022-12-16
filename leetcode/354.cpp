#include "bits/stdc++.h"

using namespace std;

// 类似堆叠正方体 以及 最长递增子序列一类题目
class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int res = 0, n = (int) envelopes.size(), dp[n];
        sort(envelopes.begin(), envelopes.end());
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// 利用排序 消除一个维度
// 注意第一个元素正序 第二个元素是逆序的
class Solution2 {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int n = envelopes.size(), len = 0;
        sort(envelopes.begin(), envelopes.end(),
             [](auto &x, auto &y)->bool {return x[0]<y[0] || (x[0]==y[0] && x[1]>y[1]);});
        vector<int> dp;
        dp.emplace_back(envelopes[0][1]);
        for (int i = 1; i < n; ++i) {
            if (envelopes[i][1] > dp.back()) {
                dp.emplace_back(envelopes[i][1]);
            } else {
                // lower_bound 找出第一个不小于x的元素，即大于等于
                auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }
        return dp.size();
    }
};
