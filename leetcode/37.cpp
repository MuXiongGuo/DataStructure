#include "vector"
#include "iostream"
#include "unordered_map"
#include "unordered_set"

using namespace std;

class Solution {
public:
    void Init(vector<vector<char>> &board, vector<unordered_set<int>> &row, vector<unordered_set<int>> &column, vector<unordered_set<int>> &block) {
        int n = board.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '.') {
                    // 转化技巧
                    int num = board[i][j] - '0';
                    row[i].insert(num);
                    column[j].insert(num);
                    // 太优雅
                    block[i/3*3+j/3].insert(num);
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>> &board) {
        vector<unordered_set<int>> row(9), column(9), block(9);

    }
};