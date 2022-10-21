#include "vector"
#include "iostream"
#include "climits"

using namespace std;

// O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int min_length = INT_MAX, start = 0;
        int tem_value = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tem_value += nums[i];
            if (tem_value >= target) {
                while (tem_value >= target) {
                    tem_value -= nums[start];
                    ++start;
                }
                int tem_length = i - start + 2;
                if (min_length > tem_length)
                    min_length = tem_length;
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return min_length == INT_MAX ? 0 : min_length;

    }
};

int main() {
    Solution s;
    vector<int> nums = {2,3,1,2,4,3,9};
    int target = 7;
    int res = s.minSubArrayLen(target, nums);
    cout << res;
    return 0;
}