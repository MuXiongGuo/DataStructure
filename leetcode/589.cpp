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
    vector<int> res;

    void dfs(Node* root) {
        if (root == nullptr)
            return;
        res.emplace_back(root->val);
        for (const auto &a : root->children)
            dfs(a);
    }

    vector<int> preorder(Node* root) {
        dfs(root);
        return res;
    }
};