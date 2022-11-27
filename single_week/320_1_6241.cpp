#include "vector"
#include "iostream"
#include "algorithm"
#include "unordered_set"
#include "map"

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
            BackTracking(nums, i + 1);
            path.pop_back();
        }
    }

    int unequalTriplets(vector<int> &nums) {
        BackTracking(nums, 0);
        return res;
    }
};

// 灵茶山  针对某一元素 a个小于x  b个等于x  c个大于x
// 其对结果的贡献就是 abc
// 依次遍历即可
// 思路简单 技巧性很强
// 第一次的start为0
class Solution2 {
public:
    int unequalTriplets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int start = 0, n = nums.size(), res = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] != nums[i + 1]) {
                res += (i - start + 1) * (start) * (n - i - 1);
                start = i + 1;
            }
        }
        return res;
    }
};

// 同样的配方 这次 不排序了，用哈希线性时间做完

class Solution3 {
public:
    int unequalTriplets(vector<int> &nums) {
        int res = 0, a = 0, c = nums.size();
        map<int, int> lookup;
        for (const auto &a:nums) {
            ++lookup[a];
        }

        int b;
        for (const auto &el: lookup) {
            b = el.second;
            c -= b;
            res += a*b*c;
            a += b;
        }
        return res;
    }
};
