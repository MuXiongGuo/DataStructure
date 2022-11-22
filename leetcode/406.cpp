#include "bits/stdc++.h"

using namespace std;

// 线性时间 线性空间 O(n)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        map<int, vector<int>> queue_count;
        vector<vector<int>> res;
        // creat map
        for (const auto &a: people) {
            queue_count[a[1]].emplace_back(a[0]);
        }
        for (const auto &a: queue_count) {

        }
    }
};