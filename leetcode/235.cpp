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

// 类似236 递归时小优化下
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        if (root->val < p->val && root->val < q->val) {
            root->left = nullptr;
            root->right = lowestCommonAncestor(root->right, p, q);
        } else if (root->val > p->val && root->val > q->val) {
            root->right = nullptr;
            root->left = lowestCommonAncestor(root->left, p, q);
        } else {
            root->left = lowestCommonAncestor(root->left, p, q);
            root->right = lowestCommonAncestor(root->right, p, q);
        }
        if (root->left && root->right)
            return root;
        if (root->left && !root->right)
            return root->left;
        if (!root->left && root->right)
            return root->right;
        return nullptr;
    }
};

// 然而 二叉搜索树 第一次遇到的 在[p q] 区间内的节点 一定是 最近公共祖先
// 选用迭代和 递归都行，用迭代的话省去了栈空间
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int max_val = p->val > q->val ? p->val : q->val;
        int min_val = p->val < q->val ? p->val : q->val;
        while (root) {
            if (root->val > min_val && root->val < max_val)
                return root;
            if (root->val > max_val)
                root = root->left;
            if (root->val < min_val)
                root = root->right;
        }
        return nullptr;
    }
};

// 更简洁的迭代
class Solution3 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            } else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } else return root;
        }
        return NULL;
    }
};
