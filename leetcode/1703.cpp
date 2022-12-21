#include "bits/stdc++.h"

using namespace std;

// 失败了 模拟
class Solution {
public:
    int minMoves(vector<int> &nums, int k) {
        int res = INT_MAX;
        vector<int> right, left;
        deque<int> index;
        for (int i = nums.size()-1; i >= 0; --i) {
            if (nums[i] == 1) {
                right.emplace_back(i);
            }
        }
        for (int i = 0; i < k; ++i) {
            if (nums[i] == 0) {
                index.emplace_back(i);
            } else {
                right.pop_back();
            }
        }
        if (index.empty()) {
            return 0;
        }
        // 开始操作
        int j = 0;
        while (j <= nums.size()-k) {
            int sum = 0, l = (int)left.size()-1, r = (int)right.size()-1;
            for (auto &id:index) {
                int tem;
                if (l<0) {
                    tem = right[r--]-id;
                } else if (r<0) {
                    tem = id-left[l--];
                } else {
                    tem = id-left[l] < right[r]-id?id-left[l--]:right[r--]-id;
                }
                sum += tem;
            }
            res = min(res, sum);
            if (nums[j] == 1) {
                left.push_back(j);
            } else {
                index.pop_front();
            }
            if (j+k < nums.size() && nums[j+k] == 1) {
                right.pop_back();
            } else {
                index.push_back(j+k);
            }
            ++j;
            if (index.empty()) {
                return 0;
            }
        }
        return res;
    }
};

// 2。滑动窗口       模拟是直着想 笨笨的
// 用滑动窗口去框住k个1，然后不断找到下一组1，并且把0移出去即可，但是 要判断这样做真的是操作次数最小吗
// 如果想明白这两点是最小的，（1）这样框一定最小 （2）把0移出去是最小的代价
// 那么代码会很简单实现  0的代价好计算 因为它们的左右代价只考虑 他的左右有多少个1就能算出来，不过也不太好计算
// 之前是暴力枚举1的位置，现在是算把0移出去，因为咱们也不知道1应该放哪里
// 还要求出0的zeros 数组，然后观察变化并统计
// 有前缀和数组可以线性时间内求出 某段区间的数值
class Solution2 {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> zeros, pre{0};
        // 生成 zeros
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                ++i;
                int sum = 0;
                while (i < nums.size()) {
                    if (nums[i] == 1) {
                        zeros.push_back(sum);
                        sum = 0;
                    } else {
                        ++sum;
                    }
                    ++i;
                }
                break;
            }
        }
        // 前缀和pre
        for (int el:zeros) {
            pre.push_back(el+pre.back());
        }
        // 计算第一个cost
        int cost = 0;
        for (int x = 1; x <= k-1; ++x) {
            if (x > k/2) {
                cost += (k-x)*zeros[x-1];
            } else {
                cost += x*zeros[x-1];
            }
        }
        // 开始滚动
        int res = cost, i = 1, j = i+k-2;
        for (; j < zeros.size(); ++j, ++i) {
            int mid = (i+j)/2;
            cost -= pre[mid]-pre[i-1];
            cost += pre[j+1]-pre[mid+k%2];
            res = min(res, cost);
        }
        return res;
    }
};

// 中位数贪心+前缀和  太妙了，也是滑动，但是能在瞬间求出 最小代价，最小代价一定是中位数位置的
class Solution3 {
    int minMoves(vector<int>& nums, int k) {
        vector<int> index_p;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]==1) {
                index_p.push_back(i-index_p.size()); // 关键点，计算最小代价时，我们减去之前有的1，得到的才是到时候需要移动的距离
            }
        }
        // 前缀和模版
        int m = index_p.size(), s[m+1];
        s[0] = 0;
        partial_sum(index_p.begin(), index_p.end(), s+1);
        int ans = INT_MAX;
        for (int i = 0; i <= m-k; ++i) {
            ans = min(ans, s[i] + s[i + k] - s[i + k / 2] * 2 - index_p[i + k / 2] * (k % 2));
        }
        return ans;
    }
};


// 中位数贪心+前缀和  太妙了，也是滑动，但是能在瞬间求出 最小代价，最小代价一定是中位数位置的
class Solution4 {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<long long> index_p;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]==1) {
                index_p.push_back(i); // 这次不-index之后再-
            }
        }
        // 前缀和模版
        long long m = index_p.size(), s[m+1];
        s[0] = 0;
        partial_sum(index_p.begin(), index_p.end(), s+1);
        long long ans = INT_MAX;
        for (int i = 0; i <= m-k; ++i) {
            ans = min(ans, (long long)s[i] + s[i + k] - s[i + k / 2] * 2 - index_p[i + k / 2] * (k % 2));
        }
        for (int i = 1; i < k; ++i) {
            ans -= i>k/2?k-i:i;
        }
        return ans;
    }
};
int main() {

    //[0,0,0,0,0,1,0,0,0,1,0,1,0,0,0]
    //3
    vector<int> nums = {1,1};
    int k = 1;
    cout << Solution2().minMoves(nums, k) << endl;
    return 0;
}