#include "vector"
#include "unordered_map"
#include "iostream"

using namespace std;

// O(n2) 时间内完成
// 要想到排列组合时 不要删除掉元素
// 以及 直接乘法就能得到有多少组
class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> lookup1, lookup2;
        int ans = 0;
        unsigned n = nums1.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                ++lookup1[nums1[i] + nums2[j]];
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                ++lookup2[nums3[i] + nums4[j]];
            }
        for (auto & a : lookup1) {
            if (lookup2.find(-a.first) != lookup2.end())
                ans += a.second * lookup2[-a.first];
        }
        return ans;
    }
};


// 官方也是 但是 构造另一组的过程中 直接得出 结果, 可以减少时间  官方更聪明 直接 += 即可(构造过程中)
class Solution2 {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> countAB;
        for (int u: A) {
            for (int v: B) {
                ++countAB[u + v];
            }
        }
        int ans = 0;
        for (int u: C) {
            for (int v: D) {
                if (countAB.count(-u - v)) {
                    ans += countAB[-u - v];
                }
            }
        }
        return ans;
    }
};

//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/4sum-ii/solution/si-shu-xiang-jia-ii-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main() {
    Solution s;
    vector<int> nums1 = {-1, -1};
    vector<int> nums2 = {-1, 1};
    vector<int> nums3 = {-1, 1};
    vector<int> nums4 = {1, -1};
    int res = s.fourSumCount(nums1, nums2, nums3, nums4);
    cout << res;
    return 0;
}