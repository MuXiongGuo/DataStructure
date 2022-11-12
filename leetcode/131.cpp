#include "string"
#include "iostream"
#include "vector"

using namespace std;

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
        if (start_index == s.size()-1) {

        }
    }

    vector<vector<string>> partition(string s) {

    }
};