#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int tem = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tem += nums[i];
            if (tem <= 0) {
                if (res < 0) {
                    res = max(res, tem);
                }
                tem = 0;
            } else {
                res = max(res, tem);
            }
        }
        return res;
    }
};