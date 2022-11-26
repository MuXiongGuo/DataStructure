#include "iostream"
#include "vector"

using namespace std;

// 暴力回溯
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
        for (int i = start_index; i <= len1-5+len2; ++i) {
            if (!path.empty()) {
                if (path.size() == 3 && path[1] != s[i]) {
                    continue;
                } else if (path.size() == 4 && path[0] != s[i]) {
                    continue;
                }
            }
            path.push_back(s[i]);
            BackTracking(s, i+1);
            path.pop_back();
        }

    }
    int countPalindromes(string s) {
        BackTracking(s, 0);
        int mod = (int) 1e9 + 7;
        return res%mod;
    }
};

int main() {
    Solution s;
    cout << s.countPalindromes("3") << endl;
    return 0;
}