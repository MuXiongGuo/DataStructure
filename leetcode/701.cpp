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


// 代码随想录中 有 递归的 两种方法 （利用返回值 1。使得不需要设置全局parent指针  2。使用parent指针）
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto res = root;
        if (!root) {
            res = new TreeNode(val);
            return res;
        }
        while (root) {
            if (root->val > val) {
                if (!root->left) {
                    root->left = new TreeNode(val);
                    return res;
                } else {
                    root = root->left;
                }
            }

            if (root->val < val) {
                if (!root->right) {
                    root->right = new TreeNode(val);
                    return res;
                } else {
                    root = root->right;
                }
            }
        }
        return res;
    }
};
