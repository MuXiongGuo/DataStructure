#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k) {
        int n = vals.size();
        vector<vector<int>> adlist(n, vector<int>());
        for (const auto &edge:edges) {
            adlist[edge[0]].push_back(vals[edge[1]]);
            adlist[edge[1]].push_back(vals[edge[0]]);
        }
        for (auto &el:adlist) {
            sort(el.begin(), el.end());
        }
        int res = INT_MIN;

        for (int i = 0; i < n; ++i) {
            int tem = vals[i];
            int m = k;
            for (int j = adlist[i].size()-1; j >= 0; --j) {
                if (m == 0){
                    break;
                }
                if (adlist[i][j] <= 0) {
                    break;
                }
                tem += adlist[i][j];
                --m;
            }
            res = max(res, tem);
        }
        return res;
    }
};
