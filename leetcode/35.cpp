#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;  // 防止溢出
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left; // left 必然为right+1
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5,6};
    int target = 0;
    int res = s.searchInsert(nums, target);
    cout << res;
    return 0;
}