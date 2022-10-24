#include "iostream"
#include "vector"
#include "tuple"
#include "unordered_map"
#include "algorithm"

using namespace std;

// n^2 时间内完成  失败的哈希
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> ans;
//        unordered_map<int, tuple<int, int>> lookup;
//        for (int i = 0; i < nums.size(); ++i) {
//            for (int j = i + 1; j < nums.size(); ++j) {
//                lookup[nums[i] + nums[j]] = {i, j};
//            }
//        }
//
//        for (int i = 0; i < nums.size(); ++i) {
//            if (lookup.count(-nums[i]))
//                if (i != get<0>(lookup[-nums[i]]) && i != get<1>(lookup[-nums[i]])) {
//                    ans.push_back({nums[i], nums[get<0>(lookup[-nums[i]])], nums[get<1>(lookup[-nums[i]])]});
//                    lookup.erase(-nums[i]);
//                }
//        }
//        return ans;
//    }
//};

// 使用双指针 外加 排序 , 排序可以使得重复元素问题得到解决, 且排序的数中 双指针 一头一尾移动, 线性时间内扫描
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int first = 0; first < n; ++first) {
            if (first != 0 && nums[first] == nums[first-1])
                continue;
            int third = n - 1;
            for (int second = first + 1; second < n; ++second) {
                if (second != first+1 && nums[second] == nums[second-1])
                    continue;
                while (nums[first] + nums[second] + nums[third] > 0 && third > second)
                    --third;
                if (third == second)
                    break;
                if (nums[first] + nums[second] + nums[third] == 0)
                    ans.push_back({nums[first], nums[second], nums[third]});
                //ans.emplace_back({nums[first], nums[second], nums[third]}); // emplace_back 是模板函数 不能这样写

            }
        }
        return ans;
    }
};




int main () {
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = s.threeSum(nums);
    for (auto i : res) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}