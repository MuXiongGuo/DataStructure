#include "vector"
#include "iostream"
#include "queue"

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// bfs
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root != nullptr) que.emplace(root);
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                auto node = que.front();
                que.pop();
                if (node->left) que.emplace(node->left);
                if (node->right) que.emplace(node->right);

                // 连接
                if (n > 0) {
                    node->next = que.front();
                }
            }
        }
        return root;
    }
};

// 因为是 完美二叉树
class Solution2 {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        auto left_most = root;
        while (left_most->left != nullptr) {
            auto head = left_most;
            while (head != nullptr) {
                head->left->next = head->right;
                if (head->next != nullptr)
                    head->right->next = head->next->left;
                head = head->next;
            }
            left_most = left_most->left;
        }
        return root;
    }
};



