#include "vector"
#include "iostream"

using namespace std;

// 贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int profit [prices.size()-1];
        for (int i = 1; i < prices.size(); ++i) {
            profit[i-1] = prices[i] - prices[i-1];
        }
        int res = 0;
        for (const auto a:profit) {
            if (a > 0) {
                res += a;
            }
        }
        return res;
    }
};