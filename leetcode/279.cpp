#include "bits/stdc++.h"

using namespace std;

// 本质完全背包 凑够的最小代价一样
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX/2);
        dp[0] = 0;
        int x = 1;
        while (x*x <= n) {
            for (int j = x*x; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j-x*x]+1);
            }
            ++x;
        }
        return dp[n];
    }
};

// 代码随想录
// 版本一
class Solution2 {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) { // 遍历背包
            for (int j = 1; j * j <= i; j++) { // 遍历物品
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};

// 版本二
class Solution3 {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) { // 遍历物品
            for (int j = i * i; j <= n; j++) { // 遍历背包
                dp[j] = min(dp[j - i * i] + 1, dp[j]);
            }
        }
        return dp[n];
    }
};