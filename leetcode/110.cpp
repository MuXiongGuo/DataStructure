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

// 递归 至 底部 查看  bool型 1法
class Solution {
public:
    bool res = true;
    int dfs(TreeNode *root) {
        if (!res)
            return 0;
        if (root == nullptr)
            return 0;
        int left_val = dfs(root->left), right_val = dfs(root->right);
        if (abs(left_val-right_val) > 1) {
            res = false;
        }
        return max(left_val, right_val)+1;
    }

    bool isBalanced(TreeNode *root) {
        dfs(root);
        return res;
    }
};


// bool型 2法
class Solution2 {
public:
    int getHeight(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left_height = getHeight(root->left);
        if (left_height == -1)
            return -1;
        int right_height = getHeight(root->right);
        if (right_height == -1 || abs(left_height-right_height) > 1)
            return -1;
        return 1+ max(left_height, right_height);
    }

    bool isBalanced(TreeNode *root) {
        return getHeight(root) != -1;
    }
};



