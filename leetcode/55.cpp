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

// 官方贪心  比我的更简洁 效率更高  我的 会循环里套循环
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int right_most = 0;
        for (int i = 0; i< nums.size(); ++i) {
            if (right_most >= i) {
                right_most = max(right_most, i+nums[i]);
            }
            if (right_most >= nums.size()-1)
                return true;
        }
        return false;
    }
};