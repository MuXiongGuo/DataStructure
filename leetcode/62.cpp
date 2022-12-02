#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        for (int i = 1; i <= m; ++i) {
            dp[i][1] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= m; ++i) {
            for (int j = 2; j <= n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m][n];
    }
};

// 优化+1
// 其实 m n大小互换是无所谓的
// 所以 我们可以 选择 小的  那个的  来操作 这样就min(m,n) 复杂度了
// 比如  if (n>m)  swap(m,n)
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n,1),cur(n,1);
        for(int i = 1;i < m;i++)
        {
            for(int j = 1;j < n;j++)
            {
                cur[j] = pre[j] + cur[j - 1];
            }
            swap(pre,cur); // cpp小精髓   可以试试 stdmove 行吗 不行 两个都有用
        }
        return pre[n-1];
    }
};

// 优化+2  只用一个 更牛比
class Solution3 {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i = 1;i < m;i++)
        {
            for(int j = 1;j < n;j++)
            {
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};

// dfs 也可以 但是会超时
class Solution4 {
private:
    int dfs(int i, int j, int m, int n) {
        if (i > m || j > n) return 0; // 越界了
        if (i == m && j == n) return 1; // 找到一种方法，相当于找到了叶子节点
        return dfs(i + 1, j, m, n) + dfs(i, j + 1, m, n);
    }
public:
    int uniquePaths(int m, int n) {
        return dfs(1, 1, m, n);
    }
};

// 数论  看 代码随想录
class Solution5 {
public:
    int uniquePaths(int m, int n) {
        long long numerator = 1; // 分子
        int denominator = m - 1; // 分母
        int count = m - 1;
        int t = m + n - 2;
        while (count--) {
            numerator *= (t--);
            while (denominator != 0 && numerator % denominator == 0) {
                numerator /= denominator;
                denominator--;
            }
        }
        return numerator;
    }
};