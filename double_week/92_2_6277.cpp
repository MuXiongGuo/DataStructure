#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int row_nums[m], column_nums[n];
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < m; ++j) {
                if (grid[j][i] == 0)
                    sum += -1;
                else
                    sum += 1;
            }
            column_nums[i] = sum;
        }

        for (int i = 0; i < m; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0)
                    sum += -1;
                else
                    sum += 1;
            }
            row_nums[i] = sum;
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            vector<int> row;
            for (int j = 0; j < n; ++j) {
                row.emplace_back(row_nums[i] + column_nums[j]);
            }
            res.emplace_back(std::move(row));
        }
        return res;
    }
};