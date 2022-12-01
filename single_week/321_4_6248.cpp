// 统计中位数
#include "vector"
#include "iostream"
#include "algorithm"
#include "bits/stdc++.h"
using namespace std;
//class Solution {
//public:
//    // 计算 C(n,m)
////    int C(int n, int m) {
////        if (m > n)
////            return 0;
////        if (m == 0)
////            return 1;
////        if (m == 1)
////            return n;
////        if (m == n)
////            return 1;
////        if (m == n-1)
////            return n;
////        return C(n-1, m) + C(n-1, m-1);
////    }
//    // 计算 C(n,m)
//    int C(int n, int m) {
//        if (m > n)
//            return 0;
//        if (m == 0)
//            return 1;
//        if (m == 1)
//            return n;
//        if (m == n)
//            return 1;
//        if (m == n-1)
//            return n;
//        int res = 1;
//        for (int i = 1; i <= m; ++i) {
//            res *= (n-i+1);
//            res /= i;
//        }
//        return res;
//    }
//
//    int countSubarrays(vector<int>& nums, int k) {
//        int index = find(nums.begin(), nums.end(), k) - nums.begin();
//        if (index == nums.size())
//            return 0;
//        int res=1;
//        int left = 0, right = 0, left_tem = k, right_tem = k;
//        for (int i = index+1; i < nums.size(); ++i) {
//            if (nums[i] > right_tem) {
//                right_tem = nums[i];
//                ++right;
//            }
//        }
//
//        for (int i = index-1; i >= 0; --i) {
//            if (nums[i] < left_tem) {
//                left_tem = nums[i];
//                ++left;
//            }
//        }
//
//        int min_val = left < right ? left : right;
//
//        for (int i = 1; i <= min_val; ++i) {
//            res += C(left, i) * C(right, i);
//        }
//
//        for (int i = 0; i <= min_val; ++i) {
//            if (i+1 > right)
//                break;
//            res += C(left, i) * C(right, i+1);
//        }
//
//        return res;
//    }
//};

//class Solution {
//public:
//    int countSubarrays(vector<int>& nums, int k) {
//
//    }
//};

//class Solution {
//public:
//    int countSubarrays(vector<int>& nums, int k) {
//        int index = find(nums.begin(), nums.end(), k) - nums.begin();
//        if (index == nums.size())
//            return 0;
//        int res = 1;
//        int left = 0, right = 0;
//        int left_index = index-1, right_index = index+1;
//        while (left_index >= 0 && right_index < nums.size() && right-left < 2 && right - left > 0) {
//            if (nums[right_index] > k) {
//                ++right;
//                ++right_index;
//            } else {
//                ++left;
//                ++right_index;
//            }
//
//            if (nums[left_index] < k) {
//                ++left;
//                --left_index;
//            } else {
//                ++right;
//                --left_index;
//            }
//
//        }
//    }
//};


// 动态规划 + 预处理(大于k的变1, 小于变-1)
// 另外 读懂这个题 也很重要
// O(n^2)
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int index = 0, n = nums.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > k) {
                nums[i] = 1;
            } else if (nums[i] < k) {
                nums[i] = -1;
            } else {
                index = i;
                nums[i] = 0;
            }
        }

        // 构建 前后缀表
        // int left[nums.size()-index]{}  变量为长度时 无法初始化
        vector<int> left(index+1), right(n-index);
        for (int i = 1; i < right.size(); ++i) {
            right[i] += nums[i+index] + right[i-1];
        }
        for (int i = 1; i < left.size(); ++i) {
            left[i] += nums[index-i] + left[i-1];
        }
        // 统计在中心位置的情况 和 偏左
        for (int i = 0; i < left.size(); ++i) {
            for (int j = 0; j < right.size(); ++j) {
                if (left[i] + right[j] == 0 || left[i] + right[j] == 1) {
                    ++res;
                }
            }
        }

        return res;
    }
};
// 黄金法则：连续子串暴力是 n^2，不连续的是 指定长度的是C(n, k) 不指定长度呢么是 2^n
// 而dp分别在这两种情况下做到了 n 和 n^2
// 另一个思想是 别总是想着 左边一个组 右边一个再比较
// 更聪明的事 右边一个 后 弄左边的时候 在 右边的 作减法，这才是聪明的，节约时间的

// 线性时间 更聪明
// 用哈希线性时间  用数组枚举还是太慢了
// 左右两个哈希表 就比较笨笨了
// 能用哈希 因为是 连续子串 上周赛那个是不连续的 所以只能枚举
class Solution2 {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int pos = find(nums.begin(), nums.end(), k) - nums.begin(), n = nums.size();
        unordered_map<int, int> cnt;
        cnt[0] = 1; // 本体  cnt代表总和为 0 个数
        for (int i = pos+1, c = 0; i < n; ++i) {
            c += nums[i] > k ? 1:-1;
            ++cnt[c];
        }

        int res = cnt[0] + cnt[1]; // 不取左边时 能符合多少种情况
        // cnt 本质上是把 右边所有情况 甚至是不取也包含进去了 cnt[0] = 1 这个就是 不取右也会多一次的情况
        // 本质上 是通过左边来访问。。。
        // 不放 0 的话 到时候可以 再各自加1也对（solution3）
        // 或者是 左右构造完再遍历，就是笨笨一点 （solution4）
        for (int i = pos-1, c = 0; i >= 0; --i) {
            c += nums[i] < k ? 1:-1;
            res += cnt[c] + cnt[c+1];
        }
        return res;
    }
};

class Solution4 {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int pos = find(nums.begin(), nums.end(), k) - nums.begin(), n = nums.size();
        unordered_map<int, int> cnt, cnt2;
        for (int i = pos+1, c = 0; i < n; ++i) {
            c += nums[i] > k ? 1:-1;
            ++cnt[c];
        }
        for (int i = pos-1, c = 0; i >= 0; --i) {
            c += nums[i] > k ? 1:-1;
            ++cnt2[c];
        }
        int res = 0;
        res += cnt[0]+cnt[1]+cnt2[0]+cnt2[1]+1;
        for (const auto &el:cnt2) {
            res += el.second * cnt[-el.first];
            res += el.second * cnt[-el.first+1];
        }
        return res;
    }
};



int main() {
    // [6,5,3,4,1,2]
    //1
    vector<int> nums = {6,5,3,4,1,2};
    int k = 1;
    Solution s;
    cout << s.countSubarrays(nums, k) << endl;
}