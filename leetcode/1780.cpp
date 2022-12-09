#include "bits/stdc++.h"

using namespace std;

// 贪心
class Solution {
public:
    int helper(int n) {
        int k = 0;
        while (n > pow(3, k)) {
            ++k;
        }
        return k;
    }

    bool checkPowersOfThree(int n) {
        while (true) {
            if (n == 2) { break;}
            int k = helper(n);
            if (n == pow(3, k)) {
                return true;
            }
            k -= 1;
            if (n >= 2* pow(3, k)) {break;}
            n -= pow(3, k);
        }
        return false;
    }
};

// 官方：进制转换问题，把题目转换成3进制，如果每一位都是0 1而没有2的话，就能成功表示 太聪明了哈
class Solution2 {
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};
