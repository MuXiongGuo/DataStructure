#include "bits/stdc++.h"

using namespace std;

// 超时了
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size(), s = (1 << n) - 1;
        int res = 0, sum = 0;
        for (int i = 0; i <= s; ++i) {
            for (int j = 0; j < n; ++j) {
                int flag = (i >> j & 1) ? 1 : -1;
                sum += flag * nums[j];
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
// 01背包的组合问题  很棒 递推公式变了
class Solution2 {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2) { return 0; } // 一定凑不出来
        int m = (sum + target) / 2;
        vector<int> dp(m + 1);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = m; j >= 0; --j) {
                if (j >= nums[i])
                    dp[j] += dp[j-nums[i]];
            }
        }
        return dp[m];
    }
};

// 回溯的写法 好好学习下
// 类似那次冰激凌配料的回溯法, 属于模拟每一步的那种
class Solution3 {
public:
    int count = 0;

    int findTargetSumWays(vector<int> &nums, int target) {
        backtrack(nums, target, 0, 0);
        return count;
    }

    void backtrack(vector<int> &nums, int target, int index, int sum) {
        if (index == nums.size()) {
            if (sum == target) {
                count++;
            }
        } else {
            backtrack(nums, target, index + 1, sum + nums[index]);
            backtrack(nums, target, index + 1, sum - nums[index]);
        }
    }
};


// 类似冰激凌  每一步都要选择时 用这种回溯 否则 用排列组合的
class Solution4 {
public:
    int res = 0;

    void dfs(int start, int target, int sum, vector<int> &nums) {
        if (start == nums.size()) {
            if (sum == target) {
                ++res;
            }
            return;
        }
        dfs(start + 1, target, sum + nums[start], nums);
        dfs(start + 1, target, sum - nums[start], nums);
    }

    int findTargetSumWays(vector<int> &nums, int target) {
        dfs(0,target,0,nums);
        return res;
    }
};

// 01背包的组合问题  很棒 递推公式变了
class Solution5 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

    }
};


int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    Solution s;
    cout << s.findTargetSumWays(nums, target) << endl;
    return 0;
}