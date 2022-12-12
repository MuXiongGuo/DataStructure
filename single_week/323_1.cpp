#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>> &grid) {
        int res = 0;
        for (auto &el:grid) {
            sort(el.begin(), el.end());
        }

        int m = grid[0].size();
        for (int j = 0; j < m; ++j) {
            int tem = INT_MIN;
            for (int i = 0; i < grid.size(); ++i) {
                tem = max(tem, grid[i][j]);
            }
            res += tem;
        }
        return res;
    }
};