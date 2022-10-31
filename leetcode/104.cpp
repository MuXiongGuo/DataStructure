#include "vector"
#include "iostream"
#include "queue"

using namespace std;


// Definition for a Node.
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
    int getMax(TreeNode* root, int depth) {
        if (root == nullptr)
            return depth;
        return max(getMax(root->left, depth+1), getMax(root->right, depth+1));
    }

    int maxDepth(TreeNode* root) {
        return getMax(root, 0);
    }
};