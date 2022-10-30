#include "vector"
#include "stack"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 中序
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        if (root != nullptr) stk.push(root);
        while (!stk.empty()) {
            root = stk.top();
            if (root != nullptr) {
                stk.pop();
                if (root->right) stk.push(root->right);
                stk.push(root);
                stk.push(nullptr);
                if (root->left) stk.push(root->left);
            } else {
                stk.pop();
                root = stk.top();
                ans.push_back(root->val);
                stk.pop();
            }
        }
        return ans;
    }
};

// 前序
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        if (root != nullptr) stk.push(root);
        while (!stk.empty()) {
            root = stk.top();
            if (root != nullptr) {
                stk.pop();
                if (root->right) stk.push(root->right);
                if (root->left) stk.push(root->left);
                stk.push(root);
                stk.push(nullptr);
            } else {
                stk.pop();
                root = stk.top();
                ans.push_back(root->val);
                stk.pop();
            }
        }
        return ans;
    }
};


// 后序
class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        if (root != nullptr) stk.push(root);
        while (!stk.empty()) {
            root = stk.top();
            if (root != nullptr) {
                stk.pop();
                stk.push(root);
                stk.push(nullptr);
                if (root->right) stk.push(root->right);
                if (root->left) stk.push(root->left);
            } else {
                stk.pop();
                root = stk.top();
                ans.push_back(root->val);
                stk.pop();
            }
        }
        return ans;
    }
};