#include "bits/stdc++.h"

using namespace std;

// 类似 之前的 要不断for循环才能得到本层的结果，下一个状态与前一个状态的所有状态有关
// 1。保持一个量不变，不断枚举出全部状态
// 2。利用到前面的状态，并能注意特殊情况
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2] = dp[1] = 1;
        for (int i = 3; i <= n; ++i) {
            // i 从3开始 因为前面的 没分解必要
            for (int j = 1; j <= i/2; ++j) {
                // 但每一小份的切割情况 应该是从1开始的，保证完整性
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};

// 另一种 我自己想到的一种  比较不好解释把
// 反正思想都是能分解成前一状态的分量即可
class Solution2 {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            dp[i] = i;
            // i 从3开始 因为前面的 没分解必要
            for (int j = 1; j <= i/2; ++j) {
                // 但每一小份的切割情况 应该是从1开始的，保证完整性
                dp[i] = max(dp[i], max(dp[j]*dp[i-j], dp[j]*dp[i-j]));
            }
        }
        return dp[n];
    }
};

// 贪心 尽可能多分解成3 4的组合
class Solution3 {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        int result = 1;
        while (n > 4) {
            result *= 3;
            n -= 3;
        }
        result *= n;
        return result;
    }
};