#include "iostream"
#include "vector"

using namespace std;

// 动态规划  线性时间  每次记录比较起始点 有些麻烦
class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1)
            return 0;
        vector<int> paces(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            paces[i] = nums[i] + i;
        }
        int index = 0, right = 0, count = 0, pre = 1;
        for (int i = 0; i < paces.size(); ++i) {
            ++count;
            right = paces[index];
            if (right >= nums.size() - 1) return count;
            int tem = right;
            for (int j = pre; j <= right; ++j) {
                if (paces[j] > tem) {
                    tem = paces[j];
                    index = j;
                }
            }
            pre = right + 1;
            right = tem;
        }
    }
};

// 贪心 自己想到的 超级简洁
class Solution2 {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1)
            return 0;
        int right_most = 0, cur_most = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > cur_most) {
                ++res, cur_most = right_most;
            }
            right_most = max(right_most, i+nums[i]);
            if (right_most >= nums.size()-1) { // 这句if是关键点
                if (i == nums.size()-1)
                    return res;
                else
                    return res+1;
            }
        }
        return res;
    }
};

// 代码随想录  摆脱if 束缚
class Solution3 {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0;    // 当前覆盖最远距离下标
        int ans = 0;            // 记录走的最大步数
        int nextDistance = 0;   // 下一步覆盖最远距离下标
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance);  // 更新下一步覆盖最远距离下标
            if (i == curDistance) {                         // 遇到当前覆盖最远距离下标
                if (curDistance != nums.size() - 1) {       // 如果当前覆盖最远距离下标不是终点
                    ans++;                                  // 需要走下一步
                    curDistance = nextDistance;             // 更新当前覆盖最远距离下标（相当于加油了）
                    if (nextDistance >= nums.size() - 1) break; // 下一步的覆盖范围已经可以达到终点，结束循环
                } else break;                               // 当前覆盖最远距离下标是集合终点，不用做ans++操作了，直接结束
            }
        }
        return ans;
    }
};