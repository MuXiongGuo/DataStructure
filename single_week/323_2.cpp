#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 1;
        bool flag = false;
        vector<int> used(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == 1) { continue; }
            int cur = nums[i];
            int tem = 1;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == (long) cur * cur) {
                    used[j] = 1;
                    flag = true;
                    ++tem;
                    cur *= cur;
                }
            }
            res = max(res, tem);
        }
        if (!flag) { return -1; }
        return res;
    }
};


class Solution2 {
public:
    int longestSquareStreak(vector<int> &nums) {
        unordered_map<int, int> lookup;
        sort(nums.begin(), nums.end());
        for (const auto &el:nums) {
            if (int(sqrt(el))*int(sqrt(el)) != el) {
                lookup.insert({el, 1});
            }else if (lookup.find(int(sqrt(el))) == lookup.end()) {
                lookup.insert({el, 1});
            }else {
                lookup.insert({el, lookup[int(sqrt(el))]+1});
            }
        }
        int res = 1;
        for (const auto &el:lookup) {
            res = max(res, el.second);
        }
        if (res == 1) {return -1;}
        return res;
    }
};