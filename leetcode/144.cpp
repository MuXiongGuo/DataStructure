#include "vector"

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
    void myPreorder(TreeNode *root, vector<int> &ans) {
        if (root == nullptr)
            return;
        ans.emplace_back(root->val);
        myPreorder(root->left, ans);
        myPreorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        myPreorder(root, ans);
        return ans;
    }
};

// 迭代法
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                res.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return res;
    }
};

