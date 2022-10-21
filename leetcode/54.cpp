#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> ans;
        int left = 0, top = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i)
                ans.push_back(matrix[top][i]);
            if (ans.size() == matrix.size() * matrix[0].size())
                break;
            ++top;
            for (int i = top; i <= bottom; ++i)
                ans.push_back(matrix[i][right]);
            if (ans.size() == matrix.size() * matrix[0].size())
                break;
            --right;
            for (int i = right; i >= left; --i)
                ans.push_back(matrix[bottom][i]);
            if (ans.size() == matrix.size() * matrix[0].size())
                break;
            --bottom;
            for (int i = bottom; i >= top; --i)
                ans.push_back(matrix[i][left]);
            if (ans.size() == matrix.size() * matrix[0].size())
                break;
            ++left;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 2,  3,  4},
                                  {5, 6,  7,  8},
                                  {9, 10, 11, 12}};
    vector<vector<int>> matrix2 = {};
    vector<int> res = s.spiralOrder(matrix2);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    return 0;
}