//
// Created by gmx on 2023/10/19.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        if (nums.size() < 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = int(nums.size()-1);


        vector<int> sums(200001, 0);
    }
};