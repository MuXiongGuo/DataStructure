#include "bits/stdc++.h"

// O(1) 解法 列出公式
// 若结果不是 整数 那么返回-1
class Solution {
public:
    int pivotInteger(int n) {
        int left_sum = 0, right_sum = 0;
        for (int i = n; i >= 0; --i) {
            left_sum = (i*i+i)/2;
            right_sum = (n+i)*(n-i+1)/2;
            if (left_sum == right_sum)
                return i;
        }
        return -1;
    }
};

class Solution2 {
public:
    int pivotInteger(int n) {
        int m = n*(n+1)/2;
        int x = sqrt(m);
        if (x*x == m) {
            return x;
        }
        return -1;
    }
};