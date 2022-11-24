#include "iostream"
#include "vector"

using namespace std;

// 回溯 会超时
// 数学题 找规律而已
// 大的数一定分割，小的不分割但是 会造成自己的额外--  本质是找规律
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0, count_add = 0, count_minus = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > right) {
                count_add = 0;
                count_minus = 0;
            } else if (nums[i] < left) {
                ++count_add;
                ++count_minus;
            } else {
                ++count_add;
                if (count_minus > 0) {--count_minus;}
            }
            res += (count_add - count_minus);
        }
        return res;
    }
};

// 学习下官方的解答
class Solution2 {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0, last1 = -1, last2 = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > right) {
                last1 = -1;
                last2 = i;
            } else if (nums[i] >= left && nums[i] <= right) {
                last1 = i;
            }
            if (last1 != -1) {
                res += last1 - last2;
            }
        }
        return res;
    }
};

// 也是官方的
// 求出 低于 lower下的所有的所有子区间 这个是非常简单的
// 再利用 两次遍历的相减。
// 不合格的是小与left   而第一个得到的是 <left 与 介于left right 之间的两部分和 相减即可
// 太聪明了
class Solution3 {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }

    int count(vector<int>& nums, int lower) {
        int res = 0, cur = 0;
        for (auto x : nums) {
            cur = x <= lower ? cur + 1 : 0;
            res += cur;
        }
        return res;
    }
};
