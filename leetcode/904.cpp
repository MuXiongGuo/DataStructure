#include "iostream"
#include "vector"
#include "unordered_set"
#include "unordered_map"

using namespace std;

// 滑动窗口
class Solution {
public:
    int totalFruit(vector<int> &fruits) {
        unordered_set<int> lookup;
        int left = 0;
        int fruit_nums = 0;
        int ans = 0;
        for (int i = 0; i < fruits.size(); ++i) {
            if (fruit_nums == 2 && lookup.find(fruits[i]) == lookup.end()) {
                int index = i-1;
                lookup.clear();
                lookup.insert(fruits[index]);
                while (lookup.find(fruits[index]) != lookup.end()) {
                    --index;
                }
                left = index+1;
                lookup.insert(fruits[i]);
            } else if (fruit_nums < 2 && lookup.find(fruits[i]) == lookup.end()) {
                ++fruit_nums;
                lookup.insert(fruits[i]);
            }

            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};


// 官方的滑动窗口  从左向右的
class Solution2 {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cnt;

        int left = 0, ans = 0;
        for (int right = 0; right < n; ++right) {
            ++cnt[fruits[right]];
            while (cnt.size() > 2) {
                auto it = cnt.find(fruits[left]);
                --it->second; // ->优先级高于--
                if (it->second == 0) {
                    cnt.erase(it);
                }
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<int> fruits = {1,0,1,4,1,4,1,2,3};
    int res = s.totalFruit(fruits);
    cout << res;
    return 0;
}
