#include "string"
#include "iostream"
#include "vector"

using namespace std;

// 很好的一道题  切割思想转成组合  以及字串选取 和 终止条件
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            ++start, --end;
        }
        return true;
    }

    void BackTracking(string &s, int start_index) {
        if (start_index == s.size()) {
            res.push_back(path);
        }
        for (int i = start_index; i < s.size(); ++i) {
            if (isPalindrome(s, start_index, i)) {
                string str = s.substr(start_index, i - start_index + 1);
                path.push_back(std::move(str));
            } else {
                continue;
            }
            BackTracking(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        BackTracking(s, 0);
        return res;
    }
};

// 用动态规划来处理 回文字串
class Solution2 {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> is_palindrome;

    void ComputePalindrome(const string &s) {
        is_palindrome.resize(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size()-1; i >= 0; --i) {
            for (int j = i; j <= s.size()-1; ++j) {
                if (i == j) {is_palindrome[i][j] = true;}
                else if (j == i+1) {is_palindrome[i][j] = (s[i] == s[j]);}
                else {is_palindrome[i][j] = (s[i] == s[j] && is_palindrome[i+1][j-1]);}
            }
        }
    }

    void BackTracking(string &s, int start_index) {
        if (start_index == s.size()) {
            res.push_back(path);
        }
        for (int i = start_index; i < s.size(); ++i) {
            if (is_palindrome[start_index][i]) {
                string str = s.substr(start_index, i - start_index + 1);
                path.push_back(std::move(str));
            } else {
                continue;
            }
            BackTracking(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        ComputePalindrome(s);
        BackTracking(s, 0);
        return res;
    }
};