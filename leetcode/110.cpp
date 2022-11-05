#include "vector"
#include "queue"
#include "stack"
#include "iostream"
#include "unordered_map"
#include "cmath"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归 至 底部 查看
class Solution {
public:
    bool res = true;
    int dfs(TreeNode *root) {
        if (!res)
            return 0;
        if (root == nullptr)
            return 0;
        if (abs(dfs(root->left) - dfs(root->right)) > 1) {
            res = false;
        }
        return max(dfs(root->left), dfs(root->right))+1;
    }

    bool isBalanced(TreeNode *root) {
        dfs(root);
        return res;
    }
};