#include "iostream"
#include "vector"

using namespace std;


// 前缀和 + 动态规划
// 难点在于找到 状态转移方程
// dp[i][j] 表示 将长度为i的区间 切成j份的最大值
// dp[n][k] 就是 答案
// 状态关系：dp[i][j] = max{dp[x][j-1]+[从x到i的平均值]}
// 为了方便计算 还要计算一个前缀和数组
// 可以发现 dp[i][j] 与 dp[i][j-1]没有关系的，没关系指的是切割的位置，比如切成2刀与3刀 3刀位置与那2刀没啥关系，需要重新遍历寻找
// 另外 尽可能的分成多份 一定比 少份的绝对值大
// 每次计算一个状态要 O(n) 共要计算n*k个状态 所以是 k*n^2

// 还有一个难点是 从右向左分 可能会觉得忽略了一些情况，实际是全部包含在内的 从右向左可以利用之前的结果，所以这里才是动态规划的本质
// eg: 右向左 ****|*  ***|**   左向右 *|****  **|***  其实这两个情况 只用一个就可全部包含，但是第二个情况没法复用之前的结果
// eg: 把5个分成3份 1+4(2份) 2+3(2份) 3+2(2份) 这就是全部的组合 仔细思考
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        double prefix[n+1];
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i-1]+nums[i-1];
        }

        // 不用数组 因为数组 默认值不是0
        vector<vector<double>> dp(n+1, vector<double>(k+1));
        for (int i = 1; i <= n; ++i) {
            dp[i][1] = prefix[i]/i;
        }

        // j=2 因为 分成两份的时候，长度为1的肯定不够分
        for (int j = 2; j <= k; ++j) {
            for (int i = j; i <= n; ++i) {
                // x 从 j-1 到 i-1 也是可以的
                for (int x = i-1; x >= j-1; --x) {
                    dp[i][j] = max(dp[i][j], dp[x][j-1]+(prefix[i]-prefix[x])/(i-x));
                }
            }
        }

        return dp[n][k];
    }
};

int main() {
    Solution s;
    vector<int> nums = {9,1,2,3,9};
    cout << s.largestSumOfAverages(nums, 3) << endl;
    return 0;
}


