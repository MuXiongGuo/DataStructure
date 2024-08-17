#include "vector"
using namespace std;
class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        int left = 0, right = k - 1;
        while (left <= right) {
            while (right >= 0 && nums[right] == val) {
                --right;
                --k;
            }
            if (left > right) {
                break;
            }
            if (nums[left] == val) {
                // myswap(nums[left], nums[right]);
                swap(nums[left], nums[right]);
                --right;
                --k;
            }
            ++left;
        }
        return k;
    }
};

// void myswap(int &a, int &b) {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

// 快慢指针
class Solution2 {
   public:
    int removeElement(vector<int>& nums, int val) {
        int quick = 0, slow = 0;
        while (quick < nums.size()) {
            if (nums[quick] != val) {
                nums[slow++] = nums[quick];
            }
            ++quick;
        }
        return slow;
    }
};
// 交换法
class Solution3 {
   public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            if (nums[left] == val) {
                swap(nums[left], nums[right]);
                right--;
            } else {
                left++;
            }
        }
        return left;
    }
};