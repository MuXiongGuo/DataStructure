#include "vector"
#include "iostream"

using namespace std;

// 回溯 个数优化剪枝
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void BackTacking(int k, int n, int start_index, int sum) {
        if (path.size() == k) {
            if (sum == k)
                res.push_back(path);
            return;
        }
        if (sum > n) {
            return;
        }
        for (int i = start_index; i <= 9 - (k - path.size()) + 1; ++i) {
            path.push_back(i);
            BackTacking(k, n, i + 1, sum + i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        BackTacking(k, n, 1, 0);
        return res;
    }
};