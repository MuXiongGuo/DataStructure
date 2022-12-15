#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        vector<int> res(queries.size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0) {
                    if (j == 0) {
                        dp[i][j] = grid[i][j];
                        continue;
                    }
                    dp[i][j] = max(grid[i][j], dp[i][j - 1]);
                } else {
                    if (j == 0) {
                        dp[i][j] = max(grid[i][j], dp[i - 1][j]);
                        continue;
                    }
                    dp[i][j] = max(grid[i][j], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        // 修正
        for (int i = n - 1; i >= 0; --i) {
            int cur_min = dp[i][m - 1];
            for (int j = m - 2; j >= 0; --j) {
                if (dp[i][j] > cur_min) {
                    dp[i][j] = max(grid[i][j], cur_min);
                }
                cur_min = max(cur_min, dp[i][j]);
            }
        }

        for (int j = m - 1; j >= 0; --j) {
            int cur_min = dp[n - 1][j];
            for (int i = n - 2; i >= 0; --i) {
                if (dp[i][j] > cur_min) {
                    dp[i][j] = max(grid[i][j], cur_min);
                }
                cur_min = max(cur_min, dp[i][j]);
            }
        }


        for (int i = 0; i < queries.size(); ++i) {
            int tem = 0;
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < m; ++y) {
                    if (dp[x][y] < queries[i])
                        ++tem;
                }
            }

            res[i] = tem;
        }
        return res;
    }
};

// 并查集
class Solution2 {
public:
    // 方向
    const int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), mn = m*n;
        // 并查集模版
        int fa[mn], size[mn];  // size是用来保存 并查询相应集团的大小
        fill(size, size+mn, 1);
        iota(fa, fa+mn, 0);
        function<int(int)> find = [&](int x)->int{return x==fa[x]?x:fa[x] = find(fa[x]);};
        auto merge = [&](int from, int to)->void {
            from = find(from);
            to = find(to);
            if (from != to) {
                fa[from] = to;
                size[to] += size[from];
            }
        };
        // 将二维矩阵 连同坐标 压缩到一个一维数组里面
        array<int, 3> a[mn];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i*n+j] = {grid[i][j], i, j};
            }
        }
        sort(a, a+mn);
        // 将询问也排个序 要不然不是从小到大的 那么没办法一次做出来
        int k = queries.size(), id[k];
        iota(id, id+k, 0);
        sort(id, id+k, [&](int x, int y)->bool {return queries[x] < queries[y];});
        // 开始统计并得到结果
        vector<int> ans(k);
        int j = 0; // j放外面 保证总的次数 只有mn次 不用多做无意义的循环
        for (int i:id) {
            int q = queries[i];
            for (; j < mn && a[j][0] < q; ++j) {
                int x1 = a[j][1], y1 = a[j][2];
                for (auto &d:dirs) {
                    int x2 = x1+d[0], y2 = y1+d[1];
                    if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && grid[x2][y2]<q) {
                        merge(x1*n+y1, x2*n+y2);
                    }
                }
            }
            if (grid[0][0] < q) {
                ans[i] = size[find(0)];
            }
        }
        return ans;
    }
};

// 利用最小堆
// 注意 小细节别重复取同一个，利用原来的数组标0记录 或者再开一个数据记录都可以的
class Solution3 {
public:
    const int dirs[4][2] = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
        int m = grid.size(), n = grid[0].size(), mn = m*n;
        // 离线查询 重排结果
        int k = queries.size(), id[k];
        iota(id, id+k, 0);
        sort(id, id+k, [&](int x, int y)->bool {return queries[x]<queries[y];});
        vector<int> ans(k); // 返回结果
        // 构建最小堆
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        grid[0][0] = 0; // 用过了
        int cnt = 0;
        for (int i:id) {
            int q = queries[i];
            while (!pq.empty() && get<0>(pq.top()) < q) {
                auto [_, x1, y1] = pq.top();
                pq.pop(); // 先pop出去后 再把新的放进来，这显然符合逻辑的
                ++cnt;   //  如果加完之后再pop的话 就不一定pop到这个了呀！！！
                for (auto &d:dirs) {
                    int x2 = x1+d[0], y2 = y1+d[1];
                    if (x2>=0 && x2<m && y2>=0 && y2<n && grid[x2][y2]!=0) {
                        pq.emplace(grid[x2][y2], x2, y2);
                        grid[x2][y2] = 0;
                    }
                }
            }
            ans[i] = cnt;
        }
        return ans;
    }
};


int main() {
    // sort本质默认按照第一个元素排序
    vector<vector<int>> vec{{2,98,99}, {39,34,56}, {100,333,43}};
    sort(vec.begin(), vec.end(), [&](vector<int> &el1, vector<int> &el2)->bool {return el1[1] < el2[1];});
    for (auto &el:vec) {
        for (auto &e:el) {
            cout << e << " ";
        }
        cout << endl;
    }
    // 逗号表达式本质
    int a = 10;
    vector<int> vec2(20);
    iota(vec2.begin(), vec2.end(), 5);
    for (auto &el:vec2) {
        cout << el << " ";
    }
}