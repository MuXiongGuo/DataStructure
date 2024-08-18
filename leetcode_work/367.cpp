class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=0, r = num, mid;
        while (l <= r) {
            mid = ((r-l)>>1) + l;
            if ((long long)mid*mid > num) {
                r = mid-1;
            } else if ((long long)mid*mid < num) {
                l = mid+1;
            } else {
                return true;
            }
        }
        return false;
    }
};
