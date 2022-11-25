#include "iostream"
#include "vector"
#include "utility"

using namespace std;

// dp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
//        int sell = 0, buy = -prices[0];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[n-1][0];
    }
};

// 状态转移只有两个情况
// 可以不用数组
class Solution2 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int sell = 0, buy = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            tie(sell, buy) = pair<int, int>(max(sell, buy+prices[i]-fee), max(buy, sell-prices[i]));
        }
        return sell;
    }
};
