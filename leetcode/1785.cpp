#include "bits/stdc++.h"

using namespace std;

// 直接用accumulate 会爆
// c++这一点不咋方便
class Solution {
public:
    int minElements(vector<int> &nums, int limit, int goal) {
        int res = 0;
        long long sum = 0;
        for (const auto &n:nums) {
            sum += n;
        }
        sum = abs(goal-sum);
        if (sum == 0) {
            return res;
        }
        res = sum/limit;
        if (sum%limit!=0) {
            ++res;
        }

        return res;
    }
};

// 这样写就不会爆了 聪明
class Solution2 {
public:
    int minElements(vector<int> &nums, int limit, int goal) {
        int res = 0;
        long long sum = accumulate(nums.begin(), nums.end(), 0ll);

        sum = abs(goal-sum);
        if (sum == 0) {
            return res;
        }
        res = sum/limit;
        if (sum%limit!=0) {
            ++res;
        }

        return res;
    }
};