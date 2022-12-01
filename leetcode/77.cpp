#include "iostream"
#include "vector"

using namespace std;

// 时间复杂度 是 k*c(n,k) k是因为 保存答案需要k
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void BackTracking(int n, int k, int start_index) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = start_index; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i);
            BackTracking(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        BackTracking(n, k, 1);
        return res;
    }
};