#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// 自己的 不用排序 每层都设哈希表 与 swap组合使用
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void BackTracking(vector<int> &nums , int start_index) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
        }
        int used[21] = {0};
        for (int i = start_index; i < nums.size(); ++i) {
            if (used[nums[i]+10]) {
                continue;
            }
            used[nums[i]+10] = 1;
            path.emplace_back(nums[i]);
            swap(nums[start_index], nums[i]);
            BackTracking(nums, start_index+1);
            swap(nums[start_index], nums[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        BackTracking(nums, 0);
        return res;
    }
};

// 错误!!!  swap的排列方法 与 相间隔比较是不合适的 会打乱  swap 配哈希表万无一失
class Solution2 {
public:
    vector<vector<int>> res;
    vector<int> path;

    void BackTracking(vector<int> &nums , int start_index) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
        }

        for (int i = start_index; i < nums.size(); ++i) {
            if (i > start_index && nums[i] == nums[i-1]) { continue;}
            path.emplace_back(nums[i]);
            swap(nums[start_index], nums[i]);
            BackTracking(nums, start_index+1);
            swap(nums[start_index], nums[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        BackTracking(nums, 0);
        return res;
    }
};

// 排序法 官方的
class Solution3 {
    vector<int> vis;

public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
        if (idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};

//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/permutations-ii/solution/quan-pai-lie-ii-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 代码随想录
class Solution4 {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used) {
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // 排序
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};