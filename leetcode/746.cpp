#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+2];
        dp[1] = 0;
        dp[2] = 0;
        for (int i = 3; i <= n+1; ++i) {
            dp[i] = min(dp[i-1]+cost[i-2], dp[i-2]+cost[i-3]);
        }
        return dp[n+1];
    }
};

// 滚动数组 优化空间
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int p = 0, q = 0, r = 0;
        int n = cost.size();
        for (int i = 3; i <= n+1; ++i) {
            p = q;
            q = r;
            r = min(p+cost[i-3], q+cost[i-2]);
        }
        return r;
    }
};
