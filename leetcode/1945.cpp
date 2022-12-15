#include "bits/stdc++.h"

using namespace std;

// 48 65 97 ascii
class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 10+96) {
                res += (s[i]-96)%10 + ((s[i]-96)/10)%10;
            } else {
                res += s[i]-96;
            }

        }
        while (--k > 0) {
            int sum = 0;
            while (res > 0) {
                sum += res%10;
                res /= 10;
            }
            res = sum;
        }
        return res;
    }
};

// 官方答案 更简洁一些 但要额外空间
// 先弄个数字串
class Solution2 {
public:
    int getLucky(string s, int k) {
        string digits;
        for (char ch: s) {
            digits += to_string(ch - 'a' + 1);
        }

        for (int i = 1; i <= k && digits.size() > 1; ++i) {
            int sum = 0;
            for (char ch: digits) {
                sum += ch - '0';
            }
            digits = to_string(sum);
        }

        return stoi(digits);
    }
};
