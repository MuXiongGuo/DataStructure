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

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        // 将root1作为最终的树根
        // 特殊
        if (!root1 && !root2)
            return nullptr;
        if (!root1 && root2)
            return root2;
        if (root1 && !root2)
            return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};