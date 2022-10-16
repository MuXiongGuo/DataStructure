#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int start = -1, end = -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target && (mid == 0 || nums[mid - 1] != target)) {
                start = mid;
                break;
            }
            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target && (mid == nums.size() - 1 || nums[mid + 1] != target)){
                end = mid;
                break;
            }
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return {start, end};
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 6;
    vector<int> res = s.searchRange(nums, target);
    cout << res[0] << " " << res[1];
    return 0;
}