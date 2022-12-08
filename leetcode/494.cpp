#include "bits/stdc++.h"

using namespace std;

// 超时了
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size(), s = (1 << n)-1;
        int res = 0, sum = 0;
        for (int i = 0; i <= s; ++i) {
           for (int j = 0; j < n; ++j) {
               int flag = (i>>j & 1)?1:-1;
               sum += flag*nums[j];
           }
           if (sum == target) {
               ++res;
           }
           sum = 0;
        }
        return res;
    }
};

// 重要的是 能想到转化为背包问题
// 取+-号状态本质 可以转化成石头问题
class Solution2 {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum+target)%2) {return 0;} // 一定凑不出来
        int m = (sum+target)/2;
        vector<int> dp(m+1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = m; j >= 0; --j) {
                if (j >= nums[i]) {
                    dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
                }
            }
        }

    }
};
int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    Solution s;
    cout << s.findTargetSumWays(nums, target) << endl;
    return 0;
}