#include "bits/stdc++.h"

using namespace std;
// 并查集 秒杀
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int fa[n];
        iota(fa, fa+n, 0);
        function<int(int)> find = [&](int x)->int {return x==fa[x]?x:fa[x]=find(fa[x]);};
        auto merge = [&](int from, int to) ->void {
            from = find(from), to = find(to);
            if (from != to) {
                fa[from] = to;
            }
        };
        for (auto &edge:edges) {
            merge(edge[0], edge[1]);
        }
        return find(source)==find(destination);
    }
};

// dfs
class Solution2 {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adlist(n);
        for (auto &edge:edges) {
            adlist[edge[0]].push_back(edge[1]);
            adlist[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        function<bool(int)> dfs = [&](int x)->bool {
            if (x == destination) {return true;}
            if (visited[x]) {return false;}
            visited[x] = true;
            for (auto &el:adlist[x]) {
                if (dfs(el)) {
                    return true;
                }
            }
            return false;
        };
        return dfs(source);
    }
};

// bfs
// dfs
class Solution3 {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adlist(n);
        for (auto &edge:edges) {
            adlist[edge[0]].push_back(edge[1]);
            adlist[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        queue<int> qu;
        qu.emplace(source);
        visited[source] = true;
        while (!qu.empty()) {
            int el = qu.front();
            if (el == destination) {
                break;
            }
            qu.pop();
            for (auto &node:adlist[el]) {
                if (!visited[node]) {
                    qu.emplace(node);
                    visited[node] = true;
                }
            }
        }
        return visited[destination];
    }
};