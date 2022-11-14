#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"

using namespace std;

// 1。回溯 与之前子集问题和不重复的问题 类似
// 避免重复 子集时 考虑后一位即可 i与i+1  之前是 i与i-1
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void BackTracking(vector<int> &nums, int start_index) {
        res.emplace_back(path);
        for (int i = start_index; i < nums.size(); ++i) {
            if (i > start_index && nums[i] == nums[i-1]) {
                continue;
            }
            path.emplace_back(nums[i]);
            BackTracking(nums, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        BackTracking(nums, 0);
        return res;
    }
};

//2。 迭代法 官方的
class Solution2 {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    // 二进制的遍历顺序与 回溯是不同的，所以(mask >> (i - 1) & 1) == 0表示它的前一位是没取的
                    // 每次都是新的数
                    // 且顺序是按照二进制来的 先从第一个数 再 只有第二个数 顺序是混乱的
                    if (i > 0 && (mask >> (i - 1) & 1) == 0 && nums[i] == nums[i - 1]) {
                        flag = false;
                        break;
                    }
                    t.push_back(nums[i]);
                }
            }
            if (flag) {
                ans.push_back(t);
            }
        }
        return ans;
    }
};
