#include "string"
#include "iostream"
#include "vector"

using namespace std;

// 1.暴力枚举
class Solution1 {
public:
    bool isPalindrome(string &s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right])
                return false;
            left++, right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int max_length = 0;
        int left, right;
        for (int i = 0; i < s.size(); ++i)
            for (int j = i; j < s.size(); ++j) {
                if (isPalindrome(s, i, j)) {
                    int tem_length = j - i + 1;
                    if (max_length < tem_length) {
                        max_length = tem_length;
                        left = i, right = j;
                    }
                }
            }

        return s.substr(left, max_length);
    }
};

// 2.动态规划
class Solution2 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1)
            return s;
        int max_length = 1, start = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
        for (int length = 2; length <= n; ++length)
            for (int i = 0; i < n; ++i) {
                int j = length + i - 1;
                if (j >= n)
                    break;
                if (s[i] == s[j]) {
                    if (length <= 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] && length > max_length)
                    max_length = length, start = i;
            }
        return s.substr(start, max_length);
    }
};

// 3.中心扩散 本质也是枚举
class Solution3 {
public:
    pair<int, int> expandAroundCenter(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right])
            --left, ++right;
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start)
                end = right1, start = left1;
            if (right2 - left2 > end - start)
                end = right2, start = left2;
        }
        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution3 s;
    string str = "babad";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}