#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

// 滑动窗口   特别重要的思想
class Solution {
public:
    unordered_map<char, int> ori, cnt;

    bool checkMap() {
        for (const auto &a: ori) {
            if (cnt[a.first] < a.second)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        int min_length = INT_MAX, left_ans = 0, left = 0;
        for (const auto &a: t)
            ++ori[a];
        for (int right = 0; right < s.size(); ++right) {
            if (ori.find(s[right]) != ori.end())
                ++cnt[s[right]];
            if (checkMap()) {
                while (checkMap()) {
                    if (ori.find(s[left]) != ori.end())
                        --cnt[s[left]];
                    ++left;
                }
                if (min_length > right - left + 2) {
                    min_length = right - left + 2;
                    left_ans = left - 1;
                }
            }
        }
        return min_length == INT_MAX ? "" : s.substr(left_ans, min_length);
    }
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    Solution solution;
    cout << solution.minWindow(s, t);
    return 0;
}

