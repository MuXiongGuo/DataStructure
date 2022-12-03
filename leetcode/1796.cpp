#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int nums[10]{};
        for (const auto &el:s) {
            if (el >= 48 && el <= 57) {
                ++nums[el-'0'];
            }
        }
        bool flag = false;
        for (int i = 9; i >= 0; --i) {
            if (nums[i] > 0 && !flag) {
                flag = true;
            } else if (nums[i] > 0 && flag) {
                return i;
            }
        }
        return -1;
    }
};