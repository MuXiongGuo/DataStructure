#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 把 size 小的放到表里 毕竟 两个表都要遍历的
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        vector<int> ans;
        unordered_map<int, int> lookup;
        for (const auto &a : nums1)
            ++lookup[a];
        for (const auto  &a : nums2)
            if (lookup.count(a) && lookup[a] != 0) {
                ans.emplace_back(a);
                --lookup[a];
            }
        return ans;
    }
};