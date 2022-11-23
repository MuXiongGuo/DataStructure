#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// 没啥难度
// 唯一坑点在于 int的范围 数据范围坑人
class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 0;
        sort(points.begin(), points.end(), compare);
        long right_most = INT64_MIN;
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] > right_most) {
                ++res;
                right_most = points[i][1];
            } else {
                right_most = min(right_most, long (points[i][1]));
            }
        }
        return res;
    }
};

