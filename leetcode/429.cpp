#include "vector"
#include "queue"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> que;
        if (root != nullptr) que.emplace(root);
        while (!que.empty()) {
            vector<int> tmp;
            int n = que.size();
            while (n--) {
                auto node = que.front();
                que.pop();
                tmp.emplace_back(node->val);
                for (const auto a:node->children)
                    que.emplace(a);
            }
            res.emplace_back(move(tmp));
        }
        return res;
    }
};