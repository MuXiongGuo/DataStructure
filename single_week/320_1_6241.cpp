#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

// 回溯
class Solution {
public:
    int res = 0;
    vector<int> path;

    void BackTracking(vector<int> &nums, int start_index) {
        if (path.size() == 3) {
            ++res;
            return;
        }
        for (int i = start_index; i < nums.size(); ++i) {
            if (!path.empty() && find(path.begin(), path.end(), nums[i]) != path.end()) {
                continue;
            }
            path.emplace_back(nums[i]);
            BackTracking(nums, i+1);
            path.pop_back();
        }
    }

    int unequalTriplets(vector<int> &nums) {
        BackTracking(nums, 0);
        return res;
    }
};