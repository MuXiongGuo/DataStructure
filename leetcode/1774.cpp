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
    void dfs(const vector<int>& toppingCosts, int p, int curCost, int& res, const int& target) {
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

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = *min_element(baseCosts.begin(), baseCosts.end());
        for (auto& b : baseCosts) {
            dfs(toppingCosts, 0, b, res, target);
        }
        return res;
    }
};


int main(){

        vector<int> baseCosts{3};
        vector<int> toppingCosts{4,5,100};
        int target = 18;
        Solution s;
        cout << s.closestCost(baseCosts, toppingCosts, target) << endl;

        return 0;
}