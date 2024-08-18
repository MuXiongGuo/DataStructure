
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#include "vector"


// 第一个小于大于 第一个小于等于
// 或者是输入+1 -1 也很方便
// 一定要判断下空 的size问题
pair<int, int> BinarySearch(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1, mid;
    while (l <= r) {
        mid = ((r - l) >> 1) + l;
        if (target <= nums[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return {l, r};
}

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto firstFind = BinarySearch(nums, target), SecondFind = BinarySearch(nums, target+1);
        auto l1 = firstFind.first, r1 = firstFind.second;
        if (l1 >= nums.size() || nums[l1] != target) {
            return {-1, -1};
        }
        auto l2 = SecondFind.first;
        return {l1, l2-1};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1};
    int target = 8;

    vector<int> result = solution.searchRange(nums, target);
    cout << "结果: [" << result[0] << ", " << result[1] << "]\n";
    int c = 0 >> 1;
    cout << c;
    return 0;
}


// 也是非常机智的
class Solution2 { 
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;

            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        } 
        return vector<int>{-1, -1};
    }
};
