#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int check[26]{};
        for (auto s:sentence) {
            ++check[s-97];
        }
        for (auto el:check) {
            if (el == 0) {
                return false;
            }
        }
        return true;
    }
};

// 二进制来记录
class Solution2 {
public:
    bool checkIfPangram(string sentence) {
        int state = 0;
        for (auto s:sentence) {
            state |= 1<<(s-97);
        }
        return state == (1 << 26)-1;
    }
};