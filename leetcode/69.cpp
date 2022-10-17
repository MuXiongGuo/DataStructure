#include "iostream"
#include "cmath"

using namespace std;

// 数学公式变换    无限逼近 但是会偏小一点点  但不会偏大
class Solution1 {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int ans = exp(0.5 * log(x));
        return (long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans;
    }
};

// 2分
class Solution2 {
public:
    int mySqrt(int x) {
        int ans = 0;
        int left = 0, right = x;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if ((long long )mid*mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
int main() {
    Solution2 s;
    int x = 123;
    int res = s.mySqrt(x);
    cout << res;
    return 0;
}