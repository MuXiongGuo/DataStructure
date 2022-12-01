#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res_index= -1, min_distance = INT_MAX, min_sum = INT_MAX;
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] != x && points[i][1] != y) {
                continue;
            }
            int dis = abs(points[i][0]-x) + abs(points[i][1]-y);
            if (dis < min_distance) {
                min_distance = dis;
                res_index = i;
                min_sum = points[i][0]+points[i][1];
            } else if (dis == min_distance && min_sum > points[i][0]+points[i][1]) {
                res_index = i;
                min_sum = points[i][0]+points[i][1];
            }
        }
        return res_index;
    }
};