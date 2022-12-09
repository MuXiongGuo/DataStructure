#include "bits/stdc++.h"

using namespace std;

// 这种本质上 是类似 回溯的 每个数的状态都是取或者不取
// 错误 的 想的太简单了
class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }

        vector<int> dp(sum + 1);

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = sum; j >= 0; --j) {
                if (nums[i] <= j) {
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
            }
        }

        // 看没隔...个 是不是正好的就能判断啦
        // 取k次 就把k个背包叠在一起  嘻嘻真聪明呀
        int m = sum / k;
        for (int i = m; i <= sum; i += m) {
            if (dp[m] != m) {
                return false;
            }

        }

        return true;
    }
};

// 正规做法
// 记忆化搜索 避免搜索到之前 重复状态 用了状态压缩
class Solution2 {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }

        int n = nums.size();
        int m = sum / k;
        vector<bool> dp(1 << n, true);

        // 排序便于剪枝
        sort(nums.begin(), nums.end());

        function<bool(int, int)> dfs = [&](int s, int val) -> bool {
            if (s == 0) {
                //所有数都用光了
                return true;
            }

            if (!dp[s]) {
                // 用过了
                return false;
            }

            dp[s] = false;

            for (int i = 0; i < n; ++i) {
                if (val + nums[i] > m) {
                    break;
                }
                if ((s >> i) & 1) {
                    if (dfs(s ^ (1 << i), (val + nums[i]) % m)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs((1 << n) - 1, 0);
    }
};

class Solution3 {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }

        int n = nums.size();
        int m = sum / k;
        vector<int> used(n);
        int count = n;
        // 排序便于剪枝
        sort(nums.begin(), nums.end());

        function<bool(int, int)> dfs = [&](int val, int start) -> bool {
            if (val == m) {
                return true;
            }

            for (int i = start; i < n; ++i) {
                if (val + nums[i] > m) {
                    break;
                }
                if (used[i]) {
                    continue;
                }
                used[i] = 1;
                n -= 1;
                if (dfs(val + nums[i], i + 1)) {
                    return true;
                }
                used[i] = 0;
                n += 1;
            }
            return false;
        };
        while (n != 0) {
            if (!dfs(0, 0)) {
                return false;
            }
        }
        return true;
    }
};


class Solution4 {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }

        int n = nums.size();
        int m = sum / k;
        vector<int> used(n);
        int count = n;
        // 排序便于剪枝
        sort(nums.begin(), nums.end());

        function<bool(int, int)> dfs = [&](int val, int start) -> bool {
            if (val == m) {
                return true;
            }

            for (int i = start; i >= 0; --i) {
                if (val + nums[i] > m) {
                    continue;
                }
                if (used[i]) {
                    continue;
                }
                used[i] = 1;
                count -= 1;
                if (dfs(val + nums[i], i - 1)) {
                    return true;
                }
                used[i] = 0;
                count += 1;
            }
            return false;
        };
        while (count != 0) {
            if (!dfs(0, n-1)) {
                return false;
            }
        }
        return true;
    }
};

class Solution5 {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k > 0) {
            return false;
        }

        int n = nums.size();
        int m = sum/k;
        vector<bool> dp(1<<n, true);

        function<bool(int, int)> dfs = [&](int s, int val)->bool {
            if (s == 0) {
                return true;
            }
            if (!dp[s]) {
                return false;
            }
            dp[s] = false;
            for (int i = 0; i < n; ++i) {
                if (val+nums[i] > m) {
                    break;
                }
                if ((s >> i)&1) {
                    if (dfs(s^(1<<i), (val+nums[i])%m)) {
                        return true;
                    }
                }
            }
            return false;
        };

        return dfs((1<<n)-1, 0);
    }
};

int main() {
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    Solution4 s;
    cout << s.canPartitionKSubsets(nums, k) << endl;
    return 0;
}


