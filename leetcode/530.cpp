#include "vector"
#include "stack"
#include "iostream"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 中序 递归
class Solution {
public:
    TreeNode *pre = nullptr;
    int min = INT_MAX;

    void helper(TreeNode *root) {
        if (root == nullptr)
            return;
        helper(root->left);
        if (pre && abs(root->val - pre->val) < min) min = abs(root->val - pre->val);
        pre = root;
        helper(root->right);
    }

    int getMinimumDifference(TreeNode *root) {
        helper(root);
        return min;
    }
};

// 中序 迭代
class Solution2 {
public:
    int getMinimumDifference(TreeNode *root) {
        TreeNode *pre = nullptr;
        stack<TreeNode*> stk;
        int min_val = INT_MAX;
        while (!stk.empty() || root) {
            if (root) {
                stk.emplace(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                if (pre) min_val = min(min_val, abs(pre->val - root->val));
                pre = root;
                root = root->right;
            }
        }
        return min_val;
    }
};
