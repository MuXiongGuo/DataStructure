#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumValue(vector<string> &strs) {
        int res = 0;
        bool flag = false;
        for (const auto &str:strs) {
            for (const auto &c:str) {
                if (c>57 || c<48) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                res = max(res, int(str.size()));
            } else {
                res = max(res, stoi(str));
            }
        }
        return res;
    }
};


// 利用异常捕获处理
// stoi的异常机制 有点垃圾 所以还是算了吧
class Solution2 {
public:
    int maximumValue(vector<string> &strs) {
        int res = 0;
        for (auto &s:strs) {
            int x;
            try {
                x = stoi(s);
            }
            catch (exception &e) {
                x = s.size();
                cout << e.what() << endl;
            }
            res = max(res, x);
        }
        return res;
    }
};

int main() {
    Solution2 s;
    vector<string> strs = {"4", "p9hkfes", "oda", "dwajdiwjoiwajiodwajowd"};
    cout << s.maximumValue(strs) << endl;
}

