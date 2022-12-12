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

