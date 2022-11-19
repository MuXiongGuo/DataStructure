#include "vector"
#include "iostream"

using namespace std;

// 贪心 两两相邻比较的 结果一定是 包含所有情况的
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> helper;
        int res = 1;
        int pre = 0;
        for (int i = 1; i < nums.size(); ++i) {
            helper.emplace_back(nums[i] - nums[i-1]);
        }
        for (int i = 0; i < helper.size(); ++i) {
            if (helper[i] == 0)
                continue;
            if (pre == 0) {
                ++res;
                pre = helper[i] > 0 ? 1:-1;
            } else if (pre * helper[i] < 0) {
                ++res;
                pre *= -1;
            }
        }
        return res;
    }
};