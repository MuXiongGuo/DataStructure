#include "algorithm"
#include "iostream"
#include "vector"

using namespace std;

// 排序 加 双指针
// 以及溢出问题  int 的最大范围问题
// 强制类型转换的写法  不能 (long long) (....) 不能写第二个括号 否则 还是溢出
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int first = 0; first < n; ++first) {
            if (first != 0 && nums[first] == nums[first - 1])
                continue;
            for (int second = first + 1; second < n; ++second) {
                if (second != first + 1 && nums[second] == nums[second - 1])
                    continue;
                int fourth = n - 1;
                for (int third = second + 1; third < n; ++third) {
                    if (third != second + 1 && nums[third] == nums[third - 1])
                        continue;
                    while (fourth > third && (long long)nums[first] + nums[second] + nums[third] + nums[fourth] > target)
                        --fourth;
                    if (fourth == third)
                        break;
                    if ((long long)nums[first] + nums[second] + nums[third] + nums[fourth] == target)
                        ans.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                }
            }
        }
        return ans;
    }
};


// 带有剪枝处理  且只用 long 就行
class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // 剪枝处理
            if (nums[k] > target && nums[k] >= 0) {
                break; // 这里使用break，统一通过最后的return返回
            }
            // 对nums[k]去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 2级剪枝处理
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                    break;
                }

                // 对nums[i]去重
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                        // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    } else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }

            }
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    auto ans = s.fourSum(nums, 0);
    for (auto &v : ans) {
        for (auto &i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}