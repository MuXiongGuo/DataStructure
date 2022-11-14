#include "iostream"
#include "vector"

using namespace std;

// 子集问题的回溯  与 131 切割回文字符串稍微有些不同
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;


    void BackTracking(vector<int> &nums, int start_index) {
        res.emplace_back(path);
        for (int i = start_index; i < nums.size(); ++i) {
            path.emplace_back(nums[i]);
            BackTracking(nums, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        BackTracking(nums, 0);
    }
};

// 利用二进制也可以
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < (1<<n); ++i) {
            vector<int> path;
            for (int j = 0; j < n; ++j) {
                if (i & (1<<j)) {
                    path.emplace_back(nums[j]);
                }
            }
            res.emplace_back(std::move(path));
        }
        return res;
    }
};
