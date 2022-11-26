#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        int a = 1, b = 1;
        for (int i = 0; i < n-3; ++i) {
            int tem = b;
            b = a;
            a += tem;
        }
        return a+b;
    }
};