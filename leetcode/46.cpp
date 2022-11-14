#include "vector"

using namespace std;

// 回溯 比较耗空间 因为used数组
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void BackTracking(vector<int> &nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            } else {
                used[i] = true;
            }
            path.emplace_back(nums[i]);
            BackTracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<bool> used(6, false);
        BackTracking(nums, used);
        return res;
    }
};

// 官方的 动态维护  排列时 为n*n!   而之前的组合 通常为n*2^n
// 动态维护 太聪明了!!!
class Solution2 {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};
