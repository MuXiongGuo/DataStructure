#include "iostream"
#include "vector"

using namespace std;

// 暴力回溯 O(C(n, 5))   C(n, 5) 本质上是 ~= n^5/120
// 显然会超时
class Solution {
public:
    int res = 0;
    string path;

    void BackTracking(string &s, int start_index) {
        if (path.size() == 5) {
            ++res;
            return;
        }
        int len1 = s.size(), len2 = path.size();
        for (int i = start_index; i <= len1 - 5 + len2; ++i) {
            if (!path.empty()) {
                if (path.size() == 3 && path[1] != s[i]) {
                    continue;
                } else if (path.size() == 4 && path[0] != s[i]) {
                    continue;
                }
            }
            path.push_back(s[i]);
            BackTracking(s, i + 1);
            path.pop_back();
        }

    }

    int countPalindromes(string s) {
        BackTracking(s, 0);
        int mod = (int) 1e9 + 7;
        return res % mod;
    }
};

// O(100*n)的时间复杂度
class Solution2 {
public:
    int countPalindromes(string s) {
        int suf[10]{}, suf2[10][10]{}, pre[10]{}, pre2[10][10]{};\
        // 先后缀  既然后缀 理所当然的 向后遍历啦
        for (int i = s.size() - 1; i >= 0; --i) {
            int number = s[i] - '0';
            for (int j = 0; j < 10; ++j) {
                suf2[number][j] += suf[j];
            }
            // 最后再 在单个的里面++ 毕竟只计算右面的
            ++suf[number];
        }

        long res = 0;
        // 再计算前缀的
        for (int i = 0; i < s.size(); ++i) {
            int number = s[i] - '0';
            // 后缀 减掉这个  suf[3][3] 那肯定先剪掉 才能正确计算
            --suf[number];
            for (int j = 0; j < 10; ++j) {
                suf2[number][j] -= suf[j];
            }

            // 计算 总共有多少组合
            for (int x = 0; x < 10; ++x) {
                for (int y = 0; y < 10; ++y) {
                    res += (long)pre2[x][y] * suf2[y][x]; // long(...) 这样写不行 因为是 乘法完了才转化
                }
            }

            // 给前缀添加上去
            for (int j = 0; j < 10; ++j) {
                // 前缀这里是 细节哦
                pre2[j][number] += pre[j];
            }
            ++pre[number];
        }
        // 1e9默认是 double
        return res % (long) (1e9+7);
    }
};


int main() {
    Solution s;
    cout << s.countPalindromes("3") << endl;
    int a = 3, b = 10;
    double c = (double ) b/a;
    return 0;
}