#include "unordered_set"
#include "vector"
#include "iostream"

using namespace std;

// 哈希表 但不是 常量空间
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> lookup;
        for (const auto &a:nums)
            lookup.insert(a);
        for (int i = 1; i < INT_MAX; ++i) {
            if (!lookup.count(i)) {
                return i;
            }
        }
    }
};

// 常数空间 线性时间
class Solution2 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; ++i)
            if (nums[i] != i+1)
                return i+1;
        return n+1;
    }
};