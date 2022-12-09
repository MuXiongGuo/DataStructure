#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > 6 * nums2.size() || nums2.size() > 6 * nums1.size()) {
            return -1;
        }

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 == sum2) {
            return 0;
        }

        int m = sum1 > sum2 ? sum1 - sum2 : sum2 - sum1;
        if (sum1 < sum2) {
            swap(nums1, nums2);
        }
        int res = 0;
        int big[7]{}, small[7]{};
        for (const auto &el: nums1) {
            ++big[el];
        }
        for (const auto &el: nums2) {
            ++small[el];
        }

        while (m > 0) {
            for (int i = 6; i >= 2; --i) {
                if (small[7 - i] > 0) {
                    m -= i-1;
                    --small[7 - i];
                    ++res;
                    break;
                } else if (big[i] > 0) {
                    m -= i-1;
                    --big[i];
                    ++res;
                    break;
                }
            }
        }

        return res;
    }
};

// 官方 更优化
// 因为 小的1 和大的6都是变化5的 直接统计在一起
// 第二个优化 比较厉害 判断diff 能否被当前 h内的 数减到0，从而选择取几个，一次循环内搞定
class Solution {
public:
    int help(vector<int>& h1, vector<int>& h2, int diff) {
        vector<int> h(7, 0);
        for (int i = 1; i < 7; ++i) {
            h[6 - i] += h1[i];
            h[i - 1] += h2[i];
        }
        int res = 0;
        for (int i = 5; i && diff > 0; --i) {
            int t = min((diff + i - 1) / i, h[i]);
            res += t;
            diff -= t * i;
        }
        return res;
    }

    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (6 * n < m || 6 * m < n) {
            return -1;
        }
        vector<int> cnt1(7, 0), cnt2(7, 0);
        int diff = 0;
        for (auto& i : nums1) {
            ++cnt1[i];
            diff += i;
        }
        for (auto& i : nums2) {
            ++cnt2[i];
            diff -= i;
        }
        if (!diff) {
            return 0;
        }
        if (diff > 0) {
            return help(cnt2, cnt1, diff);
        }
        return help(cnt1, cnt2, -diff);
    }
};

作者：LeetCode-Solution
        链接：https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/solution/tong-guo-zui-shao-cao-zuo-ci-shu-shi-shu-e3o1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main() {

    vector<int> nums1{1, 2, 3, 4, 5, 6};
    vector<int> nums2{1, 1, 2, 2, 2, 2};
    cout << Solution().minOperations(nums1, nums2) << endl;

    return 0;
}

