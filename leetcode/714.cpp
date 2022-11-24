#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res = 0, profit = 0, min_price = prices[0];
        for (int i = 0; i < prices.size(); ++i) {
            profit = max(profit, prices[i] - min_price - fee);
            if (prices[i] < min_price) {

            }
        }
        return res;
    }
};