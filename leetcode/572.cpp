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
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr)
            return false;
        if (root->val != subRoot->val)
            return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
        if (root->val == subRoot->val)
            return isSubtree(root->right, subRoot->right) && isSubtree(root->left, subRoot->left);
    }
};
