#include "bits/stdc++.h"

using namespace std;

// 学习 构建邻接表
// 其实不是很难
class Solution {
public:
    int encode(int u, int v, int n) {
        return u * n + v;
    }

    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adList(n);
        // 构建邻接表
        for (auto &edge: edges) {
            int u = edge[0], v = edge[1], nodes = edge[2];
            // 这个是双向 箭头 太坑人了
            adList[u].emplace_back(v, nodes);
            adList[v].emplace_back(u, nodes);
        }

        unordered_map<int, int> used;
        unordered_set<int> visited;
        int reachable_nodes = 0;
        // stl priority_queue 自定义的用法
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
    }
};


// 灵茶山艾府的模板套路  太强  值得 反复看
class Solution2 {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &ad_list, int start) {
        // 初始 的距离都是正无穷
        vector<int> dist(ad_list.size(), INT_MAX);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // 根据pair第一个元素排序
        pq.emplace(0, start);
        vector<int> used(ad_list.size());
        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();
            used[x] = 1;
            //if (d > dist[x]) { continue;}
            for (auto [y, wt]:ad_list[x]) {
                int new_dist = d + wt;
                if (used[y] != 1 && new_dist < dist[y]) {
                    dist[y] = new_dist;
                    pq.emplace(new_dist, y);
                }
            }
        }
        return dist;
    }



    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
        // 构建邻接表
        vector<vector<pair<int, int>>> adjacency_list(n);
        for (const auto &edge: edges) {
            int u = edge[0], v = edge[1], nodes = edge[2]+1;
            // emplace_back 并不需要花括号 又一个小细节
            adjacency_list[u].emplace_back(v, nodes);
            adjacency_list[v].emplace_back(u, nodes);
        }

        auto dist = dijkstra(adjacency_list, 0);

        int res = 0;
        // 先统计每个大点
        for (const auto &di:dist) {
            if (di <= maxMoves) {
                ++res;
            }
        }
        // 再看每条边
        for (const auto &edge:edges) {
            int u = edge[0], v = edge[1], cnt = edge[2];
            int a = max(maxMoves - dist[u], 0), b = max(maxMoves - dist[v], 0);
            res += min(a+b, cnt);
        }

        return res;
    }
};


// dijkstra 算法 稍微修改了下
class Solution3 {
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
            //if (d > dist[x]) { continue;}
            for (auto [y, wt]:ad_list[x]) {
                int new_dist = d + wt;
                if (new_dist < dist[y]) {
                    dist[y] = new_dist;
                    pq.emplace(new_dist, y);
                }
            }
        }
        return dist;
    }



    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
        // 构建邻接表
        vector<vector<pair<int, int>>> adjacency_list(n);
        for (const auto &edge: edges) {
            int u = edge[0], v = edge[1], nodes = edge[2]+1;
            // emplace_back 并不需要花括号 又一个小细节
            adjacency_list[u].emplace_back(v, nodes);
            adjacency_list[v].emplace_back(u, nodes);
        }

        auto dist = dijkstra(adjacency_list, 0);

        int res = 0;
        // 先统计每个大点
        for (const auto &di:dist) {
            if (di <= maxMoves) {
                ++res;
            }
        }
        // 再看每条边
        for (const auto &edge:edges) {
            int u = edge[0], v = edge[1], cnt = edge[2];
            int a = max(maxMoves - dist[u], 0), b = max(maxMoves - dist[v], 0);
            res += min(a+b, cnt);
        }

        return res;
    }
};

int main() {
//    pair<int ,int> a = {2, 8}, b = {3, 5};
//    cout << (a < b) << endl;
//    cout << (a > b) << endl;
//    cout << (a == b) << endl;
    // [0,1,10],[0,2,1],[1,2,2],[1,3,2]
    // 7
    Solution2 s;
    vector<vector<int>> edges = {{0, 1, 10}, {0, 2, 1}, {1, 2, 2}, {1, 3, 2}};
    int maxMoves = 7;
    int n = 4;
    cout << s.reachableNodes(edges, maxMoves, n) << endl;
    return 0;
}