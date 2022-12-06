#include "bits/stdc++.h"

using namespace std;

// 转化成 01 背包问题
// 好聪明 难想到
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = accumulate(nums.begin(), nums.end(), 0);
        if (n%2) {
            return false;
        }

        vector<int> dp(n/2+1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = dp.size()-1; j >= 0; --j) {
                if (j >= nums[i])
                    dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
            }
        }

        return dp[n/2] == n/2;
    }
};