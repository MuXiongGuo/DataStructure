#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void BackTracking(int start_index, int n, int sum, int target) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        if (sum > target)
            return;
        // TODO
        for()
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    }
};