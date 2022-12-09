#include "bits/stdc++.h"

using namespace std;

// 之前做过
// 1。最大能取到的价值
// 2。有多少种组合
// 3。现在这个是子集数量 递推公式为 dp[i][j] = max(dp[i][j], dp[i-x][j-y]+1) 类似了能取到的价值

// 时间复杂分析 O(l*mn+L) l为strs有多少个元素，L为总长度
// 空间复杂度分析O(mn)
class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int x = 0, y = 0;
        for (const auto &str: strs) {
            for (const auto &c: str) {
                if (c == '0') {
                    ++x;
                } else {
                    ++y;
                }
            }

            // 小于x 小于y 的一定是装不下的，不如不遍历了
            for (int i = m; i >= x; --i) {
                for (int j = n; j >= y; --j) {
                    dp[i][j] = max(dp[i - x][j - y] + 1, dp[i][j]);
                }
            }
            x = 0, y = 0;
        }
        return dp[m][n];
    }
};