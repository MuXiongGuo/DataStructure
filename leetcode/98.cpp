#include "vector"
#include "queue"
#include "stack"
#include "iostream"
#include "unordered_map"
#include "cmath"
#include "string"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//1. 判断其中序是不是递增的
class Solution {
public:
    vector<int> traversal_nodes;

    void InorderTraversal(TreeNode *root) {
        if (root == nullptr)
            return;
        InorderTraversal(root->left);
        traversal_nodes.emplace_back(root->val);
        InorderTraversal(root->right);
    }

    bool isValidBST(TreeNode *root) {
        InorderTraversal(root);
        for (int i = 1; i < traversal_nodes.size(); ++i) {
            if (traversal_nodes[i] <= traversal_nodes[i-1])
                return false;
        }
        return true;
    }
};

//2. 可以中途停下来
class Solution2 {
public:
    TreeNode *pre= nullptr;
    bool isValidBST(TreeNode *root) {
        if (root == nullptr)
            return true;
        bool left = isValidBST(root->left);
        if (pre && pre->val >= root->val) return false;
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};

//3. 迭代   比较基本的 前序遍历
class Solution3 {
public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (!stk.empty() || root) {
            if (root) {
                stk.emplace(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                if (prev && prev->val >= root->val) return false;
                prev = root;
                root = root->right;
            }
        }
        return true;
    }
};


int main() {
    // [15, null, 7, 6, 9]
    TreeNode *root = new TreeNode(15);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    Solution2 solution;
    cout << solution.isValidBST(root) << endl;
    return 0;
}