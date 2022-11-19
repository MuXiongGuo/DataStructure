#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        // 先试图 从左向右 把负数变正
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) break;
            if (nums[i] < 0 && k > 0) {
                --k, nums[i] *= -1;
            }
        }
        if (k % 2 == 0)
            return accumulate(nums.begin(), nums.end(), 0);
        int min_abs = INT_MAX;
        for (const auto a: nums) {
            min_abs = min(min_abs, a);
        }
        return accumulate(nums.begin(), nums.end(), 0) - 2 * min_abs;
    }
};
