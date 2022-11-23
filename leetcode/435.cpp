#include "bits/stdc++.h"

using namespace std;

// 排序后 局部最优 这种做法一定导致全局最优解
// 最少的移除次数  又不是要求 移除完后 剩下很多区间 或者 区间范围足够大
// 只关心次数
class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int res = 0, right_most = INT_MIN;
        for (int i = 0; i < intervals.size(); ++i) {
            if (right_most <= intervals[i][0]) {
                right_most = intervals[i][1];
            } else {
                ++res;
                right_most = min(right_most, intervals[i][1]);
            }
        }
        return res;
    }
};