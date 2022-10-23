#include "vector"
#include "unordered_set"

using namespace std;

// 哈希表解决方法  用排序加双指针也可以
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> ans;
        unordered_set<int> lookup;
        unordered_set<int> cnt;
        for (auto const &a: nums1)
            lookup.insert(a);
        for (auto const &a: nums2)
            cnt.insert(a);
        // 选个小的 跑的快点
        auto & obj = lookup.size() < cnt.size() ? lookup : cnt;
        auto & test= lookup.size() >= cnt.size() ? lookup : cnt;
        for (const auto &el : obj)
            if (test.find(el) != test.end())
                ans.emplace_back(el);
        return ans;
    }
};