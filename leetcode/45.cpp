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
            paces[i] = nums[i]+i;
        }
        int index = 0, right = 0, count = 0, pre = 1;
        for (int i = 0; i < paces.size(); ++i) {
            ++count;
            right = paces[index];
            if (right >= nums.size()-1) return count;
            int tem = right;
            for (int j = pre; j <= right; ++j) {
                if (paces[j] > tem) {
                    tem = paces[j];
                    index = j;
                }
            }
            pre = right+1;
            right = tem;
        }
    }
};