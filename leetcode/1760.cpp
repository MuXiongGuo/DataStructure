#include "bits/stdc++.h"

using namespace std;

// 超级好的 二分查找题目
// 我们二分枚举可以达到的最低值，然后得到结果
// 一开始 我是直接去算最理想数值，但他很可能不是最理想的，并且涉及的分解很复杂不固定
// 所以用二分枚举  绝了！！！
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int res = INT_MAX, right = -1, left = 1;
        for (auto &n:nums) {
            right = max(right, n);
        }
        while (left <= right) {
            int mid = (right-left)/2+left/2;
            unsigned long long sum = 0;
            for (auto &n:nums) {
                // 天板数值 再-1，转换为地板，但是整除的时候有问题，领/的时候-1，即可，类似区间锁定
                sum += (n-1)/mid;
            }
            if (sum <= maxOperations) {
                res = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return res;
    }
};