#include "iostream"
#include "stack"
#include "vector"
#include "algorithm"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

// 递归
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        int max_depth = 0;
        for (const auto &a:root->children)
           max_depth = max(max_depth, maxDepth(a));
        return max_depth+1;
    }
};

