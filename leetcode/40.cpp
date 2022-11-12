#include "iostream"
#include "vector"

using namespace std;

// 排序后 优化重复（要在同一层上去重复） 以及超出
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void BackTracking(int start_index, int sum, vector<int> &candidates, int target) {

        if (sum == target) {
            res.push_back(path);
            return;
        }

        for(int i = start_index; i < candidates.size() && sum+candidates[i] <= target; ++i) {
            if (i > start_index && candidates[i] == candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            BackTracking(i+1, sum+candidates[i], candidates, target);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        BackTracking(0,0,candidates,target);
        return res;
    }
};
int main() {
    Solution s;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = s.combinationSum2(candidates, target);
    for (auto &i : res) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}