#include "vector"
#include "iostream"
#include "unordered_map"
#include "unordered_set"

using namespace std;

// 思想很好  但是 用bool数组 在相应位置上的false 和 true 可以代替哈希
// 使用 STL leetcode 上跑的有点慢

class Solution {
public:
    bool flag = false;

    void Init(vector<vector<char>> &board, vector<unordered_set<int>> &row, vector<unordered_set<int>> &column,
              vector<unordered_set<int>> &block) {
        int n = board.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '.') {
                    // 转化技巧
                    int num = board[i][j] - '0';
                    row[i].insert(num);
                    column[j].insert(num);
                    // 太优雅
                    block[i / 3 * 3 + j / 3].insert(num);
                }
            }
        }
    }

    void BackTracking(vector<vector<char>> &board, int i, int j, vector<unordered_set<int>> &row,
                      vector<unordered_set<int>> &column, vector<unordered_set<int>> &block) {
        // 边界条件
        if (j == 9) {
            i += 1;
            j = 0;
        }
        // 全部扫完 那么就结束了
        if (i == 9) {
            flag = true;
            return;
        }
        // 如果当前位置有数字 那么就跳过
        if (board[i][j] != '.') {
            BackTracking(board, i, j + 1, row, column, block);
            return;
        } else {
            for (int k = 1; k <= 9; ++k) {
                // 如果当前数字在当前行、列、块中都没有出现过 那么就可以放进去
                if (row[i].find(k) == row[i].end() && column[j].find(k) == column[j].end() &&
                    block[i / 3 * 3 + j / 3].find(k) == block[i / 3 * 3 + j / 3].end()) {
                    // 放进去
                    board[i][j] = k + '0';
                    row[i].insert(k);
                    column[j].insert(k);
                    block[i / 3 * 3 + j / 3].insert(k);
                    // 继续下一个位置
                    BackTracking(board, i, j + 1, row, column, block);
                    // 如果找到答案 否则 回溯
                    if (flag) {
                        return;
                    } else {
                        board[i][j] = '.';
                        row[i].erase(k);
                        column[j].erase(k);
                        block[i / 3 * 3 + j / 3].erase(k);
                    }
                }
            }
            return;
        }
    }

    void solveSudoku(vector<vector<char>> &board) {
        vector<unordered_set<int>> row(9), column(9), block(9);
        Init(board, row, column, block);
        BackTracking(board, 0, 0,row, column, block);
    }
};

// 官方的  这个更狠 利用 二进制的位  来压缩状态
class Solution2 {
private:
    int line[9];
    int column[9];
    int block[3][3];
    bool valid;
    vector<pair<int, int>> spaces;

public:
    void flip(int i, int j, int digit) {
        line[i] ^= (1 << digit);
        column[j] ^= (1 << digit);
        block[i / 3][j / 3] ^= (1 << digit);
    }

    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        auto [i, j] = spaces[pos];
        int mask = ~(line[i] | column[j] | block[i / 3][j / 3]) & 0x1ff;
        for (; mask && !valid; mask &= (mask - 1)) {
            int digitMask = mask & (-mask);
            int digit = __builtin_ctz(digitMask);
            flip(i, j, digit);
            board[i][j] = digit + '0' + 1;
            dfs(board, pos + 1);
            flip(i, j, digit);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(line, 0, sizeof(line));
        memset(column, 0, sizeof(column));
        memset(block, 0, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                }
                else {
                    int digit = board[i][j] - '0' - 1;
                    flip(i, j, digit);
                }
            }
        }

        dfs(board, 0);
    }
};

//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/sudoku-solver/solution/jie-shu-du-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。