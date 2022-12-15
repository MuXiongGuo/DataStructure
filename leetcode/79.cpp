#include "bits/stdc++.h"

using namespace std;

// 回溯 注意别来回走 会有死循环
// used 可能会因为提前结束 而没有复原
class Solution {
public:
    bool dfs(vector<vector<char>> &board, string &word, int row, int col, int count, vector<vector<int>> &used) {
        int m = board.size(), n = board[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n || used[row][col] || word[count] != board[row][col]) {
            return false;
        }
        used[row][col] = 1;
        if (count+1 == word.size()) {
            return true;
        }
        bool up = dfs(board, word, row - 1, col, count + 1, used),
            down = dfs(board, word, row + 1, col,count + 1, used),
            left = dfs(board, word, row, col-1, count+1, used),
            right = dfs(board, word, row, col+1, count+1, used);
        used[row][col] = 0;
        return up || down || left || right;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size(), n = board[0].size();
        bool res = false;
        vector<vector<int>> used(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (word[0] == board[i][j]) {
                    res = dfs(board, word, i, j, 0, used);
                    if (res) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    // [["a","b"],["c","d"]]
    //"cdba"
    Solution s;
    vector<vector<char>> board = {{'a', 'b'}, {'c', 'd'}};
    cout << s.exist(board, "cdba") << endl;
    return 0;
}