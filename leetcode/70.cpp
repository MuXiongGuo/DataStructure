#include <utility>
#include "vector"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        int ways[n+1];
        ways[1] = 1;
        ways[2] = 2;
        for (int i = 3; i <= n; ++i) {
            ways[i] = ways[i-1] + ways[i-2];
        }

        return ways[n];
    }
};

// 常数空间维护
class Solution2 {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q;
            q = r;
            r = p+q;
        }
        return r;
    }
};

// 转换成完全背包问题
// 而且是 完全背包的排列问题
class Solution3 {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 2; ++j) {
                if (i >= j) {
                    dp[i] += dp[i-j];
                }
            }
        }
        return dp[n];
    }
};

class Solution4 {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        vector<int> dp (n);
        dp[0] = 1;
        dp[1] = 2;
        int count = 2;
        while (count != n) {
            dp[count] = dp[count-1]+dp[count-2];
            count++;
        }
        return dp[n-1];
    }
};

class Solution5 {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int pre = 1, cur = 2;
        int ans = 0;
        while (n-->2) {
            // ans = pre+cur;
            // int tmp = cur;
            // cur = ans;
            // pre = tmp;
            ans = cur+pre;
            pre = cur;
            cur = ans;
        }
        return ans;
    }
};