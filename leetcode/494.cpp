#include "bits/stdc++.h"

using namespace std;

// 超时了
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size(), s = (1 << n)-1;
        int res = 0, sum = 0;
        for (int i = 0; i <= s; ++i) {
           for (int j = 0; j < n; ++j) {
               int flag = (i>>j & 1)?1:-1;
               sum += flag*nums[j];
           }
           if (sum == target) {
               ++res;
           }
           sum = 0;
        }
        return res;
    }
};
int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    Solution s;
    cout << s.findTargetSumWays(nums, target) << endl;
    return 0;
}