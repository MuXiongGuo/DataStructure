#include "bits/stdc++.h"

using namespace std;

// 超时了 利用dijkstra 求出所有点对点的单源最短路径 最纯粹的暴力
class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &ad_list, int start) {
        // 初始 的距离都是正无穷
        vector<int> dist(ad_list.size(), INT_MAX);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // 根据pair第一个元素排序
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();
            if (d > dist[x]) { continue; }
            for (auto [y, wt]: ad_list[x]) {
                int new_dist = max(d, wt);
                if (new_dist < dist[y]) {
                    dist[y] = new_dist;
                    pq.emplace(new_dist, y);
                }
            }
        }
        return dist;
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries) {
        vector<vector<pair<int, int>>> adlist(n);
        // 构建消除重复边的临接表
        for (const auto &el: edgeList) {
            int u = el[0], v = el[1], count = el[2];

            auto p1 = find_if(adlist[u].begin(), adlist[u].end(), [&](pair<int, int> &p) { return p.first == v; });
            auto p2 = find_if(adlist[v].begin(), adlist[v].end(), [&](pair<int, int> &p) { return p.first == u; });
            if (p1 == adlist[u].end()) {
                adlist[u].emplace_back(v, count);
            } else {
                p1->second = min(p1->second, count);
            }

            if (p2 == adlist[v].end()) {
                adlist[v].emplace_back(u, count);
            } else {
                p2->second = min(p2->second, count);
            }
        }

        // 构建所有点之间的最短路径
        vector<vector<int>> lookup;
        for (int i = 0; i < n; ++i) {
            lookup.emplace_back(dijkstra(adlist, i));
        }

        vector<bool> res;
        for (auto &el: queries) {
            int u = el[0], v = el[1], limit = el[2];
            res.emplace_back(lookup[u][v] < limit);
        }

        return res;
    }
};

// 并查集
class Solution2 {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries) {
        // 离线询问
        int k = queries.size(), id[k];
        vector<bool> ans(k, false);
        iota(id, id+k, 0);
        sort(id, id+k, [&](int x, int y){return queries[x][2]<queries[y][2];});
        sort(edgeList.begin(), edgeList.end(), [&](vector<int>&x, vector<int>&y){return x[2]<y[2];});
        // 并查集
        int fa[n];
        iota(fa, fa+n, 0);
        function<int(int)> find = [&](int x)->int {return x==fa[x]?x:fa[x]=find(fa[x]);};
        auto merge = [&](int from, int to)->void {
            from = find(from), to = find(to);
            if (from != to) {
                fa[from] = to;
            }
        };
        // 核心思想，按照边权进行并查集，然后查询相应的点在不在
        int j = 0;
        for (int i:id) {
            int q = queries[i][2], qu = queries[i][0], qv = queries[i][1];
            for (; j < edgeList.size() && edgeList[j][2]<q; ++j) {
                int u = edgeList[j][0], v = edgeList[j][1];
                merge(u, v);
            }
            if (find(qu) == find(qv)) {
                ans[i] = true;
            }
        }
        return ans;
    }
};

int main() {
    Solution2 s;
    vector<vector<int>> edgeList = {{0, 1, 10}, {1, 2, 5}, {2, 3, 9}, {3, 4, 13}};
    vector<vector<int>> queries = {{0, 4, 14}, {1, 4, 13}};
    auto res = s.distanceLimitedPathsExist(5, edgeList, queries);

    return 0;
}