#include "string"
#include "stack"
#include "vector"
#include "iostream"

using namespace std;


// 1. 暴力枚举
class Solution {
public:
    pair<int, int> find_max(vector<int> &nums, int j, int i) {
        int max_index, max = INT32_MIN;
        for (int k = j; k <= i; ++k) {
            if (nums[k] > max) {
                max = nums[k];
                max_index = k;
            }
        }
        return {max, max_index};
    }


    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int max_index = -1, j = 0;
            for (int i = k-1; i < nums.size(); ++i) {
                int max;
                // 需要重新找 max_index
                if (max_index < j) {
                    max_index = find_max(nums, j, i).second;
                    max = find_max(nums, j, i).first;
                } else {
                    max = nums[max_index];
                }
                // 比较 max 与 新的值



            }
    }
};