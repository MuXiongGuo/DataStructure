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
        return end + 1;
    }
};

// 更好的双指针
class Solution2 {
public:
    int removeElement(vector<int> &nums, int val) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            if (nums[left] == val)
                nums[left] = nums[right--];
            else
                ++left;
        }
        return left;
    }
};

int main() {
    Solution2 s;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int res = s.removeElement(nums, val);
    cout << res;
    return 0;
}