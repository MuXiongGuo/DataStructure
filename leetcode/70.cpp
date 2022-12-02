#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        int ways[n+1];
        ways[1] = 1;
        ways[2] = 2;
        for (int i = 3; i <= n; ++i) {
            ways[i] = ways[i-1] + ways[i-2];
        }

        return ways[n];
    }
};

// 常数空间维护
class Solution2 {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q;
            q = r;
            r = p+q;
        }
        return r;
    }
};