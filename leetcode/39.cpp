#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void BackTracking(int start_index, int sum, vector<int> &candidates, int target) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        if (sum > target)
            return;
        for (int i = start_index; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            BackTracking(i, sum+candidates[i], candidates, target);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        BackTracking(0, 0, candidates, target);
        return res;
    }
};

// 在for循环上优化  避免进入下一层，更好一些  不过要先排序
class Solution2 {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        // 如果 sum + candidates[i] > target 就终止遍历
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();

        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end()); // 需要排序
        backtracking(candidates, target, 0, 0);
        return result;
    }
};