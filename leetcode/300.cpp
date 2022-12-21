#include "bits/stdc++.h"

using namespace std;

// 经典题目，类似堆积盒子
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size(), res = 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// 官方的贪心 + 二分查找很有趣
// 二分的经典，比如+1-1 l<=r
// 以及如何写出 找到最大且小于的元素 写法，值得复习
class Solution2 {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = 1, n = (int) nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};

// 自己写一下二分
class Solution3 {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = 0,n = nums.size(), arr[n];
        arr[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > arr[len]) {
                arr[++len] = nums[i];
            } else {
                int l = 0, r = len, pos = 0;
                // 从右向左第一个小于 nums[i]的，不会提前停下来
                while (l <= r) {
                    int mid = l+(r-l)/2;
                    if (arr[mid] < nums[i]) {
                        l = mid+1;
                    } else {
                        r = mid-1;
                        pos = mid;
                    }
                }
                arr[pos] = nums[i];
            }
        }
        return len+1;
    }
};


// 自己写一下二分
class Solution4 {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = 0,n = nums.size(), arr[n];
        arr[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > arr[len]) {
                arr[++len] = nums[i];
            } else {
                auto p = lower_bound(arr, arr+len, nums[i]);
                *p = nums[i];
            }
        }
        return len+1;
    }
};

int main() {
    vector<int> test1{1,2,4,5,7,8,10,11,12,32,34};
    vector<int> test2{1,1,2,4,5,6,6,6,7,7,8,10};
    auto find1 = [&](int x, vector<int>& nums)->int{
        // 找第一个小于x的数字
        int l = 0, r = nums.size()-1, pos = l;
        while (l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] < x) {
                l = mid+1;
                pos = mid;
            } else {
                r = mid-1;
            }
        }
        return pos;
    };

    auto find2 = [&](int x, vector<int>& nums)->int{
        // 找第一个大于x的数字
        int l = 0, r = nums.size()-1, pos = r;
        while (l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] > x) {
                r = mid-1;
                pos = mid;
            } else {
                l = mid+1;
            }
        }
        return pos;
    };

    auto find3 = [&](int x, vector<int>& nums)->int{
        // 找第一个小于等于x的数字 且尽量靠近右边
        int l = 0, r = nums.size()-1, pos = l;
        while (l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] <= x) {
                l = mid+1;
                pos = mid;
            } else {
                r = mid-1;
            }
        }
        return pos;
    };

    auto find4 = [&](int x, vector<int>& nums)->int{
        // 找第一个大于等于x的数字 且尽量靠近左边
        int l = 0, r = nums.size()-1, pos = r;
        while (l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] >= x) {
                r = mid-1;
                pos = mid;
            } else {
                l = mid+1;
            }
        }
        return pos;
    };

//    auto find5 = [&](int x, vector<int>& nums)->int{
//        // 找第一个大于等于x的数字 且尽量靠近右边
//        int l = 0, r = nums.size()-1, pos = 0;
//        while (l <= r) {
//            int mid = (l+r)/2;
//            if (nums[mid] < x) {
//                l = mid+1;
//            } else {
//                pos = mid;
//                r = mid-1;
//            }
//        }
//        return pos;
//    };
//
//    auto find6 = [&](int x, vector<int>& nums)->int{
//        // 找第一个小于等于x的数字 且尽量靠近右边
//        int l = 0, r = nums.size()-1, pos = 0;
//        while (l <= r) {
//            int mid = (l+r)/2;
//            if (nums[mid] <= x) {
//                r = mid-1;
//            } else {
//                l = mid+1;
//                pos = mid;
//            }
//        }
//        return pos;
//    };
    cout << "test1" << endl;

    cout << find1(100, test1) << endl;
    cout << find2(100, test1) << endl;
    cout << find3(100, test1) << endl;
    cout << find4(100, test1) << endl;
//    cout << find5(6, test1) << endl;
//    cout << find6(6, test1) << endl;

    cout << "test2" << endl;

    cout << find1(6, test2) << endl;
    cout << find2(6, test2) << endl;
    cout << find3(6, test2) << endl;
    cout << find4(6, test2) << endl;
//    cout << find5(6, test2) << endl;
//    cout << find6(6, test2) << endl;

}