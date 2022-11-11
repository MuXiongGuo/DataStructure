#include "vector"
#include "iostream"
#include "unordered_map"

using namespace std;

// vector中是空的 与 vector中有一个空的string是不一样的！！！
class Solution {
public:
    unordered_map<char, string> lookup = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    vector<string> res;
    string path;
    void BackTracking(string digits, int start_index) {
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        string words = lookup[digits[start_index]];
        for (int i = 0; i <= words.size()-1; ++i) {
            path.push_back(words[i]);
            BackTracking(digits, start_index+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return {};

        BackTracking(digits, 0);
        return res;
    }
};

// 学学别人的 哈希表
// 版本一
class Solution2 {
private:
    const string letterMap[10] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
    };
public:
    vector<string> result;
    string s;
    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';        // 将index指向的数字转为int
        string letters = letterMap[digit];      // 取数字对应的字符集
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);            // 处理
            backtracking(digits, index + 1);    // 递归，注意index+1，一下层要处理下一个数字了
            s.pop_back();                       // 回溯
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};