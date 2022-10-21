#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int left = 1;
        for (int right = 1; right < nums.size(); ++right)
            if (nums[left - 1] != nums[right])
                nums[left] = nums[right], ++left;
        return left;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int res = s.removeDuplicates(nums);
    cout << res;
    return 0;
}