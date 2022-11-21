#include "iostream"
#include "string"
#include "vector"

using namespace std;

// 难点在于 O(1)时间内判断出 这个位置是否能放一个皇后  因为要枚举所有情况 所以至少为O(n!)
class Solution {
public:
    vector<vector<string>> res;
    vector<int> path;

    void BackTracking(int n) {
        if (path.size() == n) {
            // 通过 vector<int> 构造一个符合条件的vector<string>
            string s(n, '.');
            vector<string> tem(n, s);
            for (int i = 0; i < n; ++i) {
                tem[i][path[i]] = 'Q';
            }
            res.emplace_back(std::move(tem));
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!path.empty()) {
                int flag = false, count = 1;
                for (auto it = path.crbegin(); it != path.crend(); ++it) {
                    if (i == *it || i == *it + count || i == *it - count) {
                        flag = true;
                        break;
                    }
                    ++count;
                }
                if (flag) {
                    continue;
                }
            }
            path.emplace_back(i);
            BackTracking(n);
            path.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        BackTracking(n);
        return res;
    }
};

// 官方解答，核心在于使用三个哈希表来达到线性时间内解决问题
// 同一右斜角的元素 其row-line 相同，同一左斜角的元素 其row+line相同
// 每次回溯时多加一个row的变量 然后进行哈希判断即可
// 回溯时 记得哈希表弹出
class Solution2 {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        auto columns = unordered_set<int>();
        auto diagonals1 = unordered_set<int>();
        auto diagonals2 = unordered_set<int>();
        backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
        return solutions;
    }

    void backtrack(vector<vector<string>> &solutions, vector<int> &queens, int n, int row, unordered_set<int> &columns, unordered_set<int> &diagonals1, unordered_set<int> &diagonals2) {
        if (row == n) {
            vector<string> board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            for (int i = 0; i < n; i++) {
                if (columns.find(i) != columns.end()) {
                    continue;
                }
                int diagonal1 = row - i;
                if (diagonals1.find(diagonal1) != diagonals1.end()) {
                    continue;
                }
                int diagonal2 = row + i;
                if (diagonals2.find(diagonal2) != diagonals2.end()) {
                    continue;
                }
                queens[row] = i;
                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);
                backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
                queens[row] = -1;
                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            }
        }
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};



// 官方 利用二进制位数 来表示不能放的
// 并且其作为 变量参数 每次 左右移
// 来达成更新的效果
// 太优雅了！！！
class Solution3 {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        solve(solutions, queens, n, 0, 0, 0, 0);
        return solutions;
    }

    void solve(vector<vector<string>> &solutions, vector<int> &queens, int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            auto board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            // 由于每次只看n位 所以超了也无所谓的
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                // 从右向左 第一个1的位置的数
                int position = availablePositions & (-availablePositions);
                // 消掉这个1 使得下次 取到别的1
                availablePositions = availablePositions & (availablePositions - 1);
                // 返回二进制 末尾0的个数的函数
                int column = __builtin_ctz(position);
                queens[row] = column;
                solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
                queens[row] = -1;
            }
        }
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};
//
//作者：LeetCode-Solution
//链接：https://leetcode.cn/problems/n-queens/solution/nhuang-hou-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

const char *returnStr() {
    const char *p = "hello world!";
    return p;
}

int main() {
    int n = 3;
    string a = "dada";
    // string 不能这样初始化  好笨笨呀
    vector<string> tem(n, (5, "dd"));
    // 顺便复习了 auto忽略顶层const
    // for（const auto）这种 这个const是指底层的毕竟仅仅针对引用
    int v = 19;
    const auto &v_7 = v;
    const auto v_6 = v;
    // 字符串常量也是个大坑
    const auto &jj = "dada";
    const char *str = NULL;//一定要初始化，好习惯
    str = returnStr();
    printf("%s\n", str);
    return 0;

}

