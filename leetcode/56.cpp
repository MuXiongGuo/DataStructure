#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), compare);
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] > end) {
                res.push_back({start, end});
                start = intervals[i][0], end = intervals[i][1];
            } else {
                end = max(end, intervals[i][1]);
            }
            if (i == intervals.size()-1) {
                res.push_back({start, end});
            }
        }
        return res;
    }
};

// 代码随想录 思想是一样的
// 方法不同
// 56题 763题 两种 完成的思想(避免了考虑边界):
// 56为 拿到这个元素先更新一下, 判断是否到指定位置了, 到了的话则处理
// 763为 (遍历前先添加第一个元素)拿到这个元素与之前的 res的back作比较 判断是否....
class Solution2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;
        // 排序的参数使用了lambda表达式
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});

        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i][0]) { // 合并区间
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
