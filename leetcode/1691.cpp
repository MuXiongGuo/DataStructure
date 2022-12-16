#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxHeight(vector<vector<int>> &cuboids) {
        int res = 0;
        for (auto &cuboid: cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end(), [&](auto &x, auto &y) -> bool { return x[2] < y[2]; });
        for (int i = cuboids.size() - 1; i >= 0; --i) {
            int x1 = cuboids[i][0], y1 = cuboids[i][1], z1 = cuboids[i][2], sum = z1;
            for (int j = i - 1; j >= 0; --j) {
                int x2 = cuboids[j][0], y2 = cuboids[j][1], z2 = cuboids[j][2];
                if (x1 >= x2 && y1 >= y2 && z1 >= z2) {
                    sum += z2;
                    x1 = x2, y1 = y2, z1 = z2;
                }
            }
            res = max(res, sum);
        }
        return res;
    }
};

// 动态规划
// 上面的是错误的暴力 要知道反例 以及如何规避
// 排序只要能保证 完全大于的一定在排在后面就行 其余的不用管
// n^2
class Solution2 {
public:
    int maxHeight(vector<vector<int>> &cuboids) {
        int n = cuboids.size();
        vector<int> dp(n);
        // 保证了 完全大的一定在完全小的右边 其余的不用管 类似拓扑
        for (auto &cuboid:cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int res = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; ++j) {
                if (cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]) {
                    dp[i] = max(dp[i], dp[j]+cuboids[i][2]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// 官方记忆化搜索
class Solution3 {
public:
    bool check(const vector<int> &a, const vector<int> &b) {
        return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (auto & v : cuboids) {
            sort(v.begin(), v.end());
        }
        sort(cuboids.begin(), cuboids.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
        });

        vector<int> memo(n, -1);
        function<int(int, int)> dfs = [&](int top, int index)->int {
            if (index == cuboids.size()) {
                return 0;
            }
            if (top != -1 && memo[top] != -1) {
                return memo[top];
            }
            int height = dfs(top, index + 1);
            if (top == -1 || check(cuboids[top], cuboids[index])) {
                height = max(height, cuboids[index][2] + dfs(index, index + 1));
            }
            if (top != -1) {
                memo[top] = height;
            }
            return height;
        };
        return dfs(-1, 0);
    }
};

int main() {
    vector<vector<int>> cuboids = {{50,  45, 20},
                                   {95,  37, 53},
                                   {45,  23, 12},
                                   {100, 1,  1},
                                   {95,  2,  1},
                                   {80,  1,  1}};
    Solution().maxHeight(cuboids);
    for (auto &cuboid: cuboids) {
        for (auto &el: cuboid) {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}