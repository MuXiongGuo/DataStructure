#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }

        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

// 滚动数组优化 空间
class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> pre(n), cur(n);
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            pre[i] = 1;
        }

        for (int i = 1; i < m; ++i) {
            // 避免 原来的1 换下来 那一排不好弄初始化的
            cur[0] = pre[0];
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    cur[j] = 0;
                    continue;
                }
                if (j >= 1) {
                    cur[j] = cur[j-1] + pre[j];
                }
            }
            swap(cur, pre);
        }
        return pre[n-1];
    }
};


// 优雅
class Solution3 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0] = obstacleGrid[0][0] == 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    // 当竖着有石头时 以后的竖0 位置 数值全为0了
                    dp[j] = 0;
                    continue;
                }
                if (j >= 1) {
                    // dp本身就是上一行
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp.back();
    }
};