#include "bits/stdc++.h"

using namespace std;

// 很有趣的完全背包，如何用最少代价凑出来
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<unsigned int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (auto &coin: coins) {
            for (int j = coin; j <= amount; ++j) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};