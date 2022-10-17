#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int end = nums.size() - 1;
        for (int i = 0; i <= end; ++i) {
            if (nums[i] == val)
                while (i <= end) {
                    if (nums[end] != val) {
                        swap(nums[i], nums[end]);
                        --end;
                        break;
                    }
                    --end;
                }
        }
        return end+1;
    }
};