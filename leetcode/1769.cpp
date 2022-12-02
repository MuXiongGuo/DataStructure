#include "bits/stdc++.h"

using namespace std;

// 利用左右总数统计 线性时间完成
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int left = 0, right = 0, left_sum = 0, right_sum = 0;
        for (int i = 1; i < boxes.size(); ++i) {
            if (boxes[i] == '1') {
                right_sum += i;
                ++right;
            }
        }

        vector<int> res(boxes.size());
        res[0] = right_sum;
        if (boxes[0] == '1') {
            left_sum = 1, left = 1;
        }

        for (int i = 1; i < boxes.size(); ++i) {
            right_sum -= right;

            res[i] = right_sum + left_sum;

            if (boxes[i] == '1') {
                --right;
                ++left;
            }
            left_sum += left;
        }
        return res;
    }
};