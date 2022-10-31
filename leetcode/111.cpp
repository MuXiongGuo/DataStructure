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

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int left, right;
        if (root->left == nullptr)
            left = INT_MAX;
        else
            left = minDepth(root->left);
        if (root->right == nullptr)
            right = INT_MAX;
        else
            right = minDepth(root->right);
        return min(left, right) + 1;
    }
};