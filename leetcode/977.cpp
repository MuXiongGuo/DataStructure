#include "iostream"
#include "vector"
#include "deque"

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        deque<int> ans;

        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            if (nums[i]*nums[i] > nums[j]*nums[j])
                ans.push_front(nums[i]*nums[i]), ++i;
            else
                ans.push_front(nums[j]*nums[j]), --j;
        }
        // vector<int> res {ans.begin(), ans.end()}; 拷贝
        vector<int> res{make_move_iterator(ans.begin()), make_move_iterator(ans.end())}; // 移动
       return res;
    }
};


// 官方的更聪明一些
class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            }
            else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> res = s.sortedSquares(nums);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    return 0;
}
