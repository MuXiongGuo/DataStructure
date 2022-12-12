#include "bits/stdc++.h"

using namespace std;

// 完全背包 的组合问题
class Solution {
public:
    int change(int amount, vector<int> &coins) {
        int res = 0;
        vector<int> dp(amount+1);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};