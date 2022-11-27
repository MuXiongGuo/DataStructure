#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool check(vector<int> &nums) {
        // 找到min的位置
        //int min_index = min_element(nums.begin(), nums.end()) - nums.begin();
        int n = nums.size();
        int min_index = 0;
        int min_val = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= min_val && (i == 0 || nums[i-1] != nums[i])) {
                min_val = nums[i];
                min_index = i;
            }
        }
        int pre = nums[min_index];
        for (int i = 1; i < n; ++i) {
            if (nums[(i+min_index)%n] < pre) {
                return false;
            }
            pre = nums[(i+min_index)%n];
        }
        return true;
    }
};


// 官方 分类讨论
class Solution2 {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), index = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i-1]) {
                index = i;
                break;
            }
        }

        if (index == 0)
            return true;

        for (int i = index+1; i < n; ++i) {
            if (nums[i] < nums[i-1])
                return false;
        }

        return nums[0] >= nums[n-1];
    }
};
