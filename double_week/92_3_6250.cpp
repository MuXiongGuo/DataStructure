#include "string"
#include "vector"
#include "iostream"

using namespace std;

//class Solution {
//public:
//    int bestClosingTime(string customers) {
//
//        int n = customers.size(), nums_Y = 0, nums_N = 0;
//        for (const auto &customer:customers) {
//            if (customer == 'Y')
//                nums_Y += 1;
//            else
//                nums_N += 1;
//        }
//        int res=0;
//        int dp[n][2];
//        // 0 是开门   1 是关门
//        dp[n-1][0] = nums_N, dp[n-1][1] = nums_Y;
//        for (int i = n-2; i >= 0; --i) {
//
//        }
//
//    }
//};

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), nums_N = 0;
        for (const auto &customer:customers) {
            if (customer == 'N')
                nums_N += 1;
        }
        int res = n, penalty_cur = nums_N, penalty_min = nums_N;
        for (int i = n-1; i >= 0; --i) {
            if (customers[i] == 'Y') {
                penalty_cur += 1;
            } else {
                penalty_cur -= 1;
            }
            if (penalty_min >= penalty_cur) {
                penalty_min = penalty_cur;
                res = i;
            }
        }
        return res;
    }
};