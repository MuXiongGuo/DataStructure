#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void BackTracking(int start_index, vector<int> &nums) {
        if (path.size() > 1)
            res.emplace_back(path);
        for (int i = start_index; i < nums.size(); ++i) {
            bool flag = false;
            if (i >start_index) {
                for (int tem = i-1; tem >= start_index; --tem) {
                    if (nums[tem] == nums[i]) {
                        flag = true;
                        continue;
                    }
                }
            }
            if (flag)
                continue;
            if (path.empty() || path[path.size()-1] <= nums[i]) {
                path.emplace_back(nums[i]);
            } else {
                continue;
            }

            BackTracking(i+1, nums);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        BackTracking(0, nums);
        return res;
    }
};

// 重复的问题 是指同层之间不能有重复的, 子集是把路径也收集进来仅此而已
class Solution2 {
public:
    vector<vector<int>> res;
    vector<int> path;

    void BackTracking(int start_index, vector<int> &nums) {
        if (path.size() > 1)
            res.emplace_back(path);
        int used[201] = {0};
        for (int i = start_index; i < nums.size(); ++i) {
            if ((!path.empty() && path.back() > nums[i]) || used[nums[i]+100] == 1)
                continue;
            used[nums[i] + 100] = 1;
            path.emplace_back(nums[i]);
            BackTracking(i+1, nums);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        BackTracking(0, nums);
        return res;
    }
};