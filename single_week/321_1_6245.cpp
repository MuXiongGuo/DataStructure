


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
