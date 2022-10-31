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

// 分治递归  错误的 递归的运行顺序不对
class Solution {
public:
    void dfs(Node* root) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            return;
        Node* current;
        if (root->left != nullptr && root->right != nullptr) {
            root->left->next = root->right;
            current = root->right;
        }
        else {
            current = root->left == nullptr ? root->right:root->left;
        }
        auto next_node = root->next;
        while (next_node != nullptr && next_node->left == nullptr && next_node->right == nullptr) next_node = next_node->next;
        if (next_node != nullptr) {
            auto obj = next_node->left== nullptr? next_node->right:next_node->left;
            current->next = obj;
        }
        dfs(root->left);
        dfs(root->right);
    }

    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};


// 绝对优雅 看成是一个个链表  每次 保存虚拟头节点 既能回到前面 又能 方便统一
class Solution2 {
public:
    Node* connect(Node* root) {
        auto current = root;
        while (current != nullptr) {
            auto pre = new Node();
            auto dummy = pre;
            while (current != nullptr) {
                if (current->left != nullptr) {
                    pre->next = current->left;
                    pre = pre->next;
                }
                if (current->right != nullptr) {
                    pre->next = current->right;
                    pre = pre->next;
                }
                current = current->next;
            }
            current = dummy->next;
        }
        return root;
    }
};


int main() {
    // [2,1,3,0,7,9,1,2,null,1,0,null,null,8,8,null,null,null,null,7]
    auto root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->left->left = new Node(0);
    root->left->right = new Node(7);
    root->right->left = new Node(9);
    root->right->right = new Node(1);
    root->left->left->left = new Node(2);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(0);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(8);
    root->left->right->right->left = new Node(7);
    Solution().connect(root);
    return 0;
}