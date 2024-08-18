#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        while (left <= right) {
            mid = left+(right-left)/2;
            if (nums[mid] > target) {
                right = mid-1;
            } else if (nums[mid] < target) {
                left = mid+1;
            } else {
                return mid;
            }
        }
        return left;
    }
};