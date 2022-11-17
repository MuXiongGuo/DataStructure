#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int position = 0;
        while (position != nums.size()-1) {
            if (nums[position] == 0) return false;
            int pace = nums[position];
            int max_income = 0, max_position;
            for (int i = position+1; i <= position+pace; ++i) {
                if (i + nums[i] >= nums.size()-1) return true;
                if (max_income < i + nums[i]) {
                    max_income = i + nums[i];
                    max_position = i;
                }
            }
            position = max_position;
        }
        return true;

    }
};