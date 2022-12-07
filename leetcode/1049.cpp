#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int val1 = sum/2;
        vector<int> dp(val1+1);
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = val1; j >= 0; --j) {
                if (j >= stones[i]) {
                    dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
                }
            }
        }
        return sum-2*dp[val1];
    }
};

