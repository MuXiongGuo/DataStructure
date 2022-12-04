#include "bits/stdc++.h"

using namespace std;

// dfs
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // 构建临接表
        vector<vector<pair<int, int>>> adjacency_list(n+1);
        for (const auto &road: roads) {
            int u = road[0], v = road[1], weight = road[2];
            // emplace_back 并不需要花括号 又一个小细节
            adjacency_list[u].emplace_back(v, weight);
            adjacency_list[v].emplace_back(u, weight);
        }

        // dfs
//        vector<vector<int>> visited(n+1, vector<int>(n+1));
        vector<int> visited(n+1);
        int res = INT_MAX;
        function<void(int)> dfs = [&](int u) {
            visited[u] = 1;
            for (auto [v, weight]: adjacency_list[u]) {
                if (visited[v] == 0) {
                    res = min(res, weight);
                    dfs(v);
                }
            }
            visited[u] = 0;
        };
        dfs(1);
        return res;
    }
};

// 测试每条边 会造成三次方节点的 复杂度 所以很笨蛋
class Solution2 {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // 构建临接表
        vector<vector<pair<int, int>>> adjacency_list(n+1);
        for (const auto &road: roads) {
            int u = road[0], v = road[1], weight = road[2];
            // emplace_back 并不需要花括号 又一个小细节
            adjacency_list[u].emplace_back(v, weight);
            //adjacency_list[v].emplace_back(u, weight);
        }

        // dfs
        vector<vector<int>> visited(n+1, vector<int>(n+1));

        int res = INT_MAX;
        function<void(int)> dfs = [&](int u) {
            for (auto [v, weight]: adjacency_list[u]) {
                if (visited[u][v] == 0) {
                    visited[u][v] = 1, visited[v][u] = 1;
                    res = min(res, weight);
                    dfs(v);
                }
            }
        };
        dfs(1);
        return res;
    }
};

class Solution3 {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // 构建临接表
        vector<vector<pair<int, int>>> adjacency_list(n+1);
        for (const auto &road: roads) {
            int u = road[0], v = road[1], weight = road[2];
            // emplace_back 并不需要花括号 又一个小细节
            adjacency_list[u].emplace_back(v, weight);
            adjacency_list[v].emplace_back(u, weight);
        }

        // dfs
//        vector<vector<int>> visited(n+1, vector<int>(n+1));
        vector<int> visited(n+1);
        int res = INT_MAX;
        function<void(int)> dfs = [&](int u) {
            visited[u] = 1;
            for (auto &[v, weight]: adjacency_list[u]) {
                if (visited[v] == 0) {
                    dfs(v);
                }
            }
        };
        dfs(1);
        for (const auto &el:roads) {
            if (visited[el[0]]) {
                res = min(res, el[2]);
            }
        }
        return res;
    }
};



// 正规做法 dfs 模版
class Solution4 {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> ad_list(n+1);
        for (const auto &road:roads) {
            int u = road[0], v = road[1], count = road[2];
            ad_list[u].emplace_back(v, count);
            ad_list[v].emplace_back(u, count);
        }

        vector<int> visited(n+1);
        int res = INT_MAX;
        // 定义函数对象
        function<void(int)> dfs = [&] (int start) -> void {
            visited[start] = 1;
            for (const auto &[v, el]: ad_list[start]) {
                // 先取边 再判断细节
                res = min(res, el);
                if (visited[v] == 0) {
                    dfs(v);
                }
            }
        };
        dfs(1);
        return res;
    }
};

int main() {


}
