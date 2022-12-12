#include "bits/stdc++.h"

using namespace std;

// 愚蠢
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

// 排序后 每次加入到
class Solution2 {
public:
    int longestSquareStreak(vector<int> &nums) {
        unordered_map<int, int> lookup;
        sort(nums.begin(), nums.end());
        for (const auto &el: nums) {
            if (int(sqrt(el)) * int(sqrt(el)) != el) {
                lookup.insert({el, 1});
            } else if (lookup.find(int(sqrt(el))) == lookup.end()) {
                lookup.insert({el, 1});
            } else {
                lookup.insert({el, lookup[int(sqrt(el))] + 1});
            }
        }
        int res = 1;
        for (const auto &el: lookup) {
            res = max(res, el.second);
        }
        if (res == 1) { return -1; }
        return res;
    }
};

// 聪明的暴力哈希，把所有元素加入set中，开始枚举单个的，判断其平方的在不在，也不用在意重复问题，
// n*loglogm 的时间复杂度
class Solution3 {
public:
    int longestSquareStreak(vector<int> &nums) {
        int res = 0;
        unordered_set<long> lookup(nums.begin(), nums.end());
        for (auto &el: nums) {
            int tem = 0;
            long x = el;
            while (lookup.count(x)) {
                ++tem;
                x *= x;
            }
            res = max(res, tem);
        }
        return res > 1 ? res : -1;
    }
};

// 记忆化搜索
int longestSquareStreak(vector<int> &nums) {
    set<int> st(nums.begin(), nums.end());
    int ans = 0;

    // 记忆化搜索
    vector<int> cache(1e5 + 1);
    function<int(int)> dfs = [&](int x) -> int {
        int sq = sqrt(x);
        if (sq * sq != x || !st.count(sq)) {
            return 1;
        }
        if (cache[x]) {
            return cache[x];
        }
        int res = 1 + dfs(sq);
        cache[x] = res;
        return res;
    };

    for (auto &x: st) {
        ans = max(ans, dfs(x));
    }

    return ans > 1 ? ans : -1;
}

// sqrt 防止爆int  线性时间内完成
class Solution5 {
public:
    int longestSquareStreak(vector<int> &nums) {
        int res = 1;
        vector<int> dp(1e5+1);
        unordered_set<int> lookup(nums.begin(), nums.end());
        function<int(int)> dfs = [&](int x)->int {
            if (dp[x]) {return dp[x];}
            int s = sqrt(x);
            if (s*s != x || !lookup.count(s)) {
                return 1;
            }
            int res = 1+dfs(s);
            dp[x] = res;
            return res;
        };

        for (const auto &n:nums) {
            res = max(res, dfs(n));
        }

        return res>1?res:-1;
    }
};