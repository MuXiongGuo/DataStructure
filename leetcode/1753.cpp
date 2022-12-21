#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int n = 0, res = 0;
        while (n < 2) {
            ++res;
            if (a > b) {
                swap(a, b);
            }
            if (b > c) {
                swap(b, c);
            }
            if (--b==0) {
                ++n;
            }
            if (--c == 0) {
                ++n;
            }
        }
        return res;
    }
};

// 官方答案，其实有公式直接能算出来
// 分两种情况，c>=a+b  和 c<a+b
// 公式推导看官网即可
// 情况2推导，设a用了k1 b用了k2  res = k1+k2+(a-k1+b-k2)/2   因为在匹配过程中 我们贪心匹配，所以最后ab之间的差最大为1 故可以用除法
class Solution2 {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a + b + c;
        int maxVal = max({a, b, c}); // 三元最大  牛逼
        if (sum - maxVal < maxVal) {
            return sum - maxVal;
        } else {
            return sum / 2;
        }
    }
};


int main() {
    // 很神奇! 不能返回引用
    int a = 10, b = 7, d = 5;
    auto c = max(&a, max(&d, &b));
    *c = 23;
    cout << a << b << d;
}