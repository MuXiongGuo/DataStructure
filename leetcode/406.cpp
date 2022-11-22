#include "bits/stdc++.h"

using namespace std;

// O(n^2)
class Solution {
public:
    // 身高小的在前面 相同则看位次
    static bool compare(vector<int> &a, vector<int> &b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        } else {
            return a[1] < b[1];
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> res(people.size());
        for (int i = 0; i < people.size(); ++i) {
            int k = people[i][1], index = 0;
            while (k >= 0) {
                if (res[index].empty() || res[index][0] == people[i][0]) {
                    --k;
                }
                ++index;
            }
            res[index-1] = std::move(people[i]);
        }
        return res;
    }
};

// 代码随想录
// 相当聪明
// 先排高的, 相同高的 按照index 的逆向排序 保证了每次插入时都能是最佳位置
int main() {
    Solution solution;
    vector<vector<int>> people = {{7, 0},
                                  {4, 4},
                                  {7, 1},
                                  {5, 0},
                                  {6, 1},
                                  {5, 2}};
    auto res = solution.reconstructQueue(people);
    for (const auto &a: res) {
        cout << a[0] << " " << a[1] << endl;
    }
    return 0;
}