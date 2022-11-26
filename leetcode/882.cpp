#include "bits/stdc++.h"

using namespace std;

// 学习 构建邻接表
// 其实不是很难
class Solution {
public:
    int encode(int u, int v, int n) {
        return u * n + v;
    }

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adList(n);
        // 构建邻接表
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], nodes = edge[2];
            // 这个是双向 箭头 太坑人了
            adList[u].emplace_back(v, nodes);
            adList[v].emplace_back(u, nodes);
        }

        unordered_map<int, int> used;
        unordered_set<int> visited;
        int reachable_nodes = 0;
        // stl priority_queue 自定义的用法
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.emplace(0 ,0);
    }
};