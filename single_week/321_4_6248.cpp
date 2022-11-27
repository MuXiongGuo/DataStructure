// 统计中位数
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;
//class Solution {
//public:
//    // 计算 C(n,m)
////    int C(int n, int m) {
////        if (m > n)
////            return 0;
////        if (m == 0)
////            return 1;
////        if (m == 1)
////            return n;
////        if (m == n)
////            return 1;
////        if (m == n-1)
////            return n;
////        return C(n-1, m) + C(n-1, m-1);
////    }
//    // 计算 C(n,m)
//    int C(int n, int m) {
//        if (m > n)
//            return 0;
//        if (m == 0)
//            return 1;
//        if (m == 1)
//            return n;
//        if (m == n)
//            return 1;
//        if (m == n-1)
//            return n;
//        int res = 1;
//        for (int i = 1; i <= m; ++i) {
//            res *= (n-i+1);
//            res /= i;
//        }
//        return res;
//    }
//
//    int countSubarrays(vector<int>& nums, int k) {
//        int index = find(nums.begin(), nums.end(), k) - nums.begin();
//        if (index == nums.size())
//            return 0;
//        int res=1;
//        int left = 0, right = 0, left_tem = k, right_tem = k;
//        for (int i = index+1; i < nums.size(); ++i) {
//            if (nums[i] > right_tem) {
//                right_tem = nums[i];
//                ++right;
//            }
//        }
//
//        for (int i = index-1; i >= 0; --i) {
//            if (nums[i] < left_tem) {
//                left_tem = nums[i];
//                ++left;
//            }
//        }
//
//        int min_val = left < right ? left : right;
//
//        for (int i = 1; i <= min_val; ++i) {
//            res += C(left, i) * C(right, i);
//        }
//
//        for (int i = 0; i <= min_val; ++i) {
//            if (i+1 > right)
//                break;
//            res += C(left, i) * C(right, i+1);
//        }
//
//        return res;
//    }
//};

int main() {
    // [6,5,3,4,1,2]
    //1
    vector<int> nums = {6,5,3,4,1,2};
    int k = 1;
    Solution s;
    cout << s.countSubarrays(nums, k) << endl;
}

//class Solution {
//public:
//    int countSubarrays(vector<int>& nums, int k) {
//
//    }
//};

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int index = find(nums.begin(), nums.end(), k) - nums.begin();
        if (index == nums.size())
            return 0;
        int res = 1;
        int left = 0, right = 0;
        int left_index = index-1, right_index = index+1;
        while (left_index >= 0 && right_index < nums.size() && right-left < 2 && right - left > 0) {
            if (nums[right_index] > k) {
                ++right;
                ++right_index;
            } else {
                ++left;
                ++right_index;
            }

            if (nums[left_index] < k) {
                ++left;
                --left_index;
            } else {
                ++right;
                --left_index;
            }

        }
    }
};