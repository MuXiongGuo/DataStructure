#include "bits/stdc++.h"

using namespace std;

// 二叉搜索 题目自然转化为有集中形态
// 然后 自然的dp即可
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= i-1; ++j) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};