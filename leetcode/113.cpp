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
    vector<vector<int>> res;

    void dfs(TreeNode *p, vector<int> &vec, int count) {
        if (!p->left && !p->right && count == 0) {
            res.emplace_back(vector<int>(vec));
        }
        if (p->left) {
            vec.emplace_back(p->left->val);
            count -= p->left->val;
            dfs(p->left, vec, count);
            vec.pop_back();
            count += p->left->val;
        }
        if (p->right) {
            vec.emplace_back(p->right->val);
            count -= p->right->val;
            dfs(p->right, vec, count);
            vec.pop_back();
            count += p->right->val;
        }

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return res;
        vector<int> tmp{root->val};
        dfs(root, tmp, targetSum-root->val);
        return res;
    }
};