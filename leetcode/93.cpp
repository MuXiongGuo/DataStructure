#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> path;

    bool IsCorrect(string &s) {
        if (s[0] == '0' && s.size() > 1)
            return false;
        if (s.size() > 3)
            return false;
        int num = stoi(s);
        if (num > 255)
            return false;
        return true;
    }

    void BackTracking(string &s, int start_index, int times) {
        if (start_index <= (int(s.size()) - 1) && times == 3) {
            string sub_str = s.substr(start_index, s.size() - start_index);
            if (IsCorrect(sub_str)) {
                path.push_back(std::move(sub_str));
                string tem;
                for (const auto &a: path) {
                    tem += a;
                    tem += '.';
                }
                tem.pop_back();
                res.push_back(std::move(tem));
                path.pop_back();
            }
            return;
        }
        // s.size() unsigned int 类型 不能出现负数！！！
        for (int i = start_index; i < (int(s.size())+times-3); ++i) {
            string sub_str = s.substr(start_index, i - start_index + 1);
            if (IsCorrect(sub_str)) {
                path.push_back(std::move(sub_str));
                BackTracking(s, i + 1, times + 1);
                path.pop_back();
            } else {
                continue;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        BackTracking(s, 0, 0);
        return res;
    }
};

int main() {
    Solution s;
    string str = "25";
    auto res = s.restoreIpAddresses(str);
    for (const auto &a: res) {
        cout << a << endl;
    }
    return 0;
}