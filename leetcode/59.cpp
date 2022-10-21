#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int number = n * n;
        int row = 0, column = 0;
        for (int i = 1; i <= number; ++i) {
            bool up = false, down = false, right = false, left = false;
            matrix[row][column] = i;
            if (row > 0 && matrix[row - 1][column] == 0)
                up = true;
            if (row < n - 1 && matrix[row + 1][column] == 0)
                down = true;
            if (column > 0 && matrix[row][column - 1] == 0)
                left = true;
            if (column < n - 1 && matrix[row][column + 1] == 0)
                right = true;
            // 开始根据 flag 移动
            if (right && !up)
                ++column;
            else if (down && !right)
                ++row;
            else if (left && !down)
                --column;
            else if (up && !left)
                --row;
        }
        return matrix;
    }
};

// 更优雅的 每填充一层 直接削掉一层
class Solution2 {
public:
    vector<vector<int>> generateMatrix(int n) {
        int t = 0;      // top
        int b = n-1;    // bottom
        int l = 0;      // left
        int r = n-1;    // right
        vector<vector<int>> ans(n,vector<int>(n));
        int k=1;
        while(k<=n*n){
            for(int i=l;i<=r;++i,++k) ans[t][i] = k;
            ++t;
            for(int i=t;i<=b;++i,++k) ans[i][r] = k;
            --r;
            for(int i=r;i>=l;--i,++k) ans[b][i] = k;
            --b;
            for(int i=b;i>=t;--i,++k) ans[i][l] = k;
            ++l;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> res = s.generateMatrix(3);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}