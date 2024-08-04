#include "vector"
using namespace std;
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size();

        for (; i <= j;) {
            int k = (i + j) / 2;
            if (nums[k] < target) {
                i = k + 1;
            } else if (nums[k] > target) {
                j = k - 1;
            } else {
                return k;
            }
        }
        return -1;
    }
};