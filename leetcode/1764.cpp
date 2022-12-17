#include "bits/stdc++.h"

using namespace std;

// 利用kmp算法进行匹配
// 谈到匹配就要用kmp加速
class Solution {
public:
    void GetNext(int *next, vector<int> &group) {
        int j = 0;
        for (int i = 0; i < group.size(); ++i) {
            if (i == 0) {
                next[i] = 0;
                continue;
            }
            while (j>0 && group[i]!=group[j]) {
                j = next[j-1];
            }
            if (group[i] == group[j]) {
                ++j;
            }
            next[i] = j;
        }
    }


    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int start = 0;
        for (auto &group:groups) {
            bool tem = false;
            int j = 0, n = group.size(), next[n];
            GetNext(next, group);
            for (; start<nums.size();++start) {
                while (j>0 && group[j] != nums[start]) {j = next[j-1];}
                if (group[j] == nums[start]) {
                    ++j;
                }
                if (j == n) {
                    tem = true;
                    ++start;
                    break;
                }
            }
            if (!tem) {
                return false;
            }
        }
        return true;
    }
};

// 贪心 双指针
class Solution2 {
public:
    bool check(vector<int> &nums, vector<int> &group, int start) {
        if (nums.size()-start < group.size()) {
            return false;
        }
        for (int i = 0; i < group.size(); ++i) {
            if (group[i] != nums[start]) {
                return false;
            }
            ++start;
        }
        return true;
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int j = 0;
        for (auto &group:groups) {
            if (j == nums.size()) {
                return false;
            }
            while (!check(nums, group, j)) {
                ++j;
                if (j == nums.size()) {
                    return false;
                }
            }
            j += group.size();
        }
        return true;
    }
};






int main() {
    //groups = [[1,2,3],[3,4]], nums = [7,7,1,2,3,4,7,7]
    vector<vector<int>> groups = {{1,2,3},{3,4}};
    vector<int> nums = {7,7,1,2,3,4,7,7};
    Solution s;
    cout << s.canChoose(groups, nums) << endl;
    return 0;
}