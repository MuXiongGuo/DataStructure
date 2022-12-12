#include "bits/stdc++.h"

using namespace std;

// 数据不多 直接回溯
// 超时了
class Solution {
public:
    unordered_map<int, int> used;
    int res_tmp;

    int helper(int base, vector<int> &topping, int target) {
        if (base >= target) {
            return base;
        }
        int ret = base;
        for (const auto &el: topping) {
            if (used[el] == 0) {
                continue;
            }
            --used[el];
            int ans = helper(ret + el, topping, target);
            if (ans == target) {
                return target;
            }
            if (abs(ans - target) < abs(base - target) || (abs(ans - target) == abs(base - target) && ans < base)) {
                base = ans;
            }
            ++used[el];
        }

        return base;
    }

    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
        for (const auto &el: toppingCosts) {
            ++used[el];
            ++used[el];
        }

        int res = baseCosts[0];
        for (const auto &el: baseCosts) {
            if (el == target) {
                return target;
            }
            int tmp = helper(el, toppingCosts, target);
            if (tmp == target) { return tmp; }
            if (abs(tmp - target) < abs(res - target) || (abs(res - target) == abs(tmp - target) && tmp < res)) {
                res = tmp;
            }
        }
        return res;
    }
};

// 这个题的回溯 思路堪称一绝
// 只维护一个res
// 并且完美解决了 只能选两个配料的思路
class Solution2 {
public:
    void dfs(const vector<int> &toppingCosts, int p, int curCost, int &res, const int &target) {
        // 再增加也没有意义了  此处细节是不加 abs  因为 只是过大才没意义 过小还是可以的，这样还可以早点停止
        if (abs(res - target) < curCost - target) {
            return;
        } else if (abs(res - target) >= abs(curCost - target)) {
            // 替换成新的
            if (abs(res - target) > abs(curCost - target)) {
                res = curCost;
            } else {
                res = min(res, curCost);
            }
        }
        if (p == toppingCosts.size()) {
            return;
        }
        // 每一步都可以选择 不取 取1份 取2份 太聪明了 不一定非要 套for循环
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p] * 2, res, target);
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p], res, target);
        dfs(toppingCosts, p + 1, curCost, res, target);
    }

    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
        int res = *min_element(baseCosts.begin(), baseCosts.end());
        for (auto &b: baseCosts) {
            dfs(toppingCosts, 0, b, res, target);
        }
        return res;
    }
};

// 转化为01背包，因为是最接近，所以最大背包容量为2*target-x 显然哦
class Solution3 {
public:
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
        int res = baseCosts[0];
        function<void(int)> helper = [&](int base) -> void {
            if (base == target) {
                res = target;
                return;
            }

            if (base > target) {
                if (abs(target-base) < abs(target-res)) {
                    res = base;
                }
                return;
            }

            int m = 2 * target - base;
            vector<int> dp(m + 1, base);
            for (int i = 0; i < toppingCosts.size(); ++i) {
                for (int j = m; j >= toppingCosts[i]; --j) {
                    for (int k = 1; k <= 2 && j >= k * toppingCosts[i]; ++k) {
                        dp[j] = max(dp[j], dp[j - k * toppingCosts[i]] + k * toppingCosts[i]);
                    }
                }
            }
            int count = min(abs(target-res), abs(target-base));  // 选最小的间隔数值 优化一下
            for (int i = target-count; i <= target+count; ++i) {
                if (dp[i] == target) {
                    res = target;
                    return;
                }

                if (abs(dp[i]-target) < abs(res-target)) {
                    res = dp[i];
                }

                if (abs(dp[i]-target) == abs(res-target) && dp[i] < res) {
                    res = dp[i];
                }
            }
            return;
        };
        for (const auto &base:baseCosts) {
            helper(base);
            if (res == target) {
                return res;
            }
        }
        return res;
    }
};

// 官方的dp 时间复杂度 极高 看官网解析TODO 还没学会呢 只是记录一下
class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int x = *min_element(baseCosts.begin(), baseCosts.end());
        if (x >= target) {
            return x;
        }
        vector<bool> can(target + 1, false);
        int res = 2 * target - x;
        for (auto& b : baseCosts) {
            if (b <= target) {
                can[b] = true;
            } else {
                res = min(res, b);
            }
        }
        for (auto& t : toppingCosts) {
            for (int count = 0; count < 2; ++count) {
                for (int i = target; i; --i) {
                    if (can[i] && i + t > target) {
                        res = min(res, i + t);
                    }
                    if (i - t > 0) {
                        can[i] = can[i] | can[i - t];
                    }
                }
            }
        }
        for (int i = 0; i <= res - target; ++i) {
            if (can[target - i]) {
                return target - i;
            }
        }
        return res;
    }
};

作者：LeetCode-Solution
        链接：https://leetcode.cn/problems/closest-dessert-cost/solution/zui-jie-jin-mu-biao-jie-ge-de-tian-dian-2ck06/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main() {

    vector<int> baseCosts{3};
    vector<int> toppingCosts{4, 5, 100};
    int target = 18;
    Solution s;
    cout << s.closestCost(baseCosts, toppingCosts, target) << endl;

    return 0;
}