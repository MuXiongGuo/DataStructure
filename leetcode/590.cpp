#include "iostream"
#include "stack"
#include "vector"

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

class Solution {
public:
    vector<int> postorder(Node *root) {
        vector<int> res;
        stack<Node *> stk;
        if (root != nullptr) stk.emplace(root);
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            if (node != nullptr) {
                stk.emplace(node);
                stk.emplace(nullptr);
                for(auto it = node->children.rbegin(); it != node->children.rend(); ++it)
                    stk.emplace(*it);
            } else {
                res.emplace_back(stk.top()->val);
                stk.pop();
            }
        }
        return res;
    }
};