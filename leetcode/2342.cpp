#include "bits/stdc++.h"
#include "iostream"
#include "unordered_map"
#include "vector"
#include "algorithm"

using namespace std;

// 时间复杂度较高 n*logU+n*logn


// s
class Solution {
public:
    int maximumSum(vector<int> &nums) {
        unordered_map<int, vector<int>> maps;
        for (auto el: nums) {
            int c = 0;
            int el_copy = el;
            while (el != 0) {
                c += el % 10;
                el /= 10;
            }
            maps[c].push_back(el_copy);
        }
        for (auto &el: maps) {
            sort(el.second.begin(), el.second.end(), [](int a, int b) { return a > b; });
        }
        int ans = -1;
        for (const auto &el: maps) {
            if (el.second.size() >= 2) {
                ans = max(ans, el.second[0] + el.second[1]);
            }
        }
        return ans;
    }
};

// 灵神 n*logU
class Solution2 {
public:
    int maximumSum(vector<int> &nums) {
        int ans = -1;
        int sum_map[82]{}; // 至多 9 个 9 相加
        for (auto num: nums) {
            int s = 0;
            for (int x = num; x; x /= 10) {
                s += x % 10;
            }
            if (sum_map[s]) {
                ans = max(ans, num+sum_map[s]);
            }
            sum_map[s] = max(sum_map[s], num);
        }
        return ans;
    }
};

int main() {
    Solution s;
   

    vector<int> nums = {34, 23, 1, 24, 75, 33, 54, 8};

    int aa = nums.size();
    
    cout << s.maximumSum(nums) << endl;
    return 0;
}