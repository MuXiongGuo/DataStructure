#include "vector"
#include "queue"
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

class Solution {
public:
    bool check(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot)
            return true;
        if ((!root && subRoot) || (root && !subRoot) || (root->val != subRoot->val))
            return false;
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }

    bool dfs (TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr)
            return false;
        return check(root, subRoot) || dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        return dfs(root, subRoot);
    }
};
