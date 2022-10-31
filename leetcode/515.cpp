#include "vector"
#include "queue"
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if (root != nullptr) que.emplace(root);
        while (!que.empty()) {
            int n = que.size();
            int max_value = INT_MIN;
            while (n--) {
                auto node = que.front();
                que.pop();
                if (node->left) que.emplace(node->left);
                if (node->right) que.emplace(node->right);
                max_value = max(max_value, node->val);
            }
            res.emplace_back(max_value);
        }
        return res;
    }
};


class Solution2 {
public:
    vector<int> res;

    void dfs(TreeNode* root, int levels) {
        if (root == nullptr)
            return;
        if (res.size() > levels) {
            res[levels] = max(res[levels], root->val);
        } else {
            res.emplace_back(root->val);
        }
        dfs(root->left, levels+1);
        dfs(root->right, levels+1);
    }

    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};
