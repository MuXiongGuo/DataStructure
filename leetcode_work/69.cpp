// 二分查找合适的数值，然后对比即可，没有什么数学知识
class Solution {
   public:
    int mySqrt(int x) {
        int l = 0, r = x / 2, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (mid*mid == x) {
                return mid;
            } else if ((long long)mid*mid > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l-1;
    }
};