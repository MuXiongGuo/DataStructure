#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxJump(vector<int> &stones) {
        int res = 0;
        int n = stones.size();
        if (stones.size()%2 == 0) {
            for (int i = 0; i+2 < stones.size(); i+=2) {
                res = max(res, stones[i+2]-stones[i]);
            }
            res = max(res, stones[n-1]-stones[n-2]);
            res = max(res, stones[1]-stones[0]);
            for (int i = stones.size()-1; i-2 >= 0; i-=2) {
                res = max(res, stones[i]-stones[i-2]);
            }
        } else {
            for (int i = 0; i+2 < stones.size(); i+=2) {
                res = max(res, stones[i+2]-stones[i]);
            }
            res = max(res, stones[n-1]-stones[n-2]);
            for (int i = n-2; i-2 >= 0; i-=2) {
                res = max(res, stones[i]-stones[i-2]);
            }
        }
        return res;
    }
};
