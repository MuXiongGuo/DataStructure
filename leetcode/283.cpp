#include "iostream"
#include "vector"

using namespace std;

// 同方向移动的双指针
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] != 0)
                swap(nums[left], nums[right]), ++left;
        }
    }
};

int main(){
Solution s;
    vector<int> nums = {0,1,0,3,12};
    s.moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << " ";
    return 0;
}