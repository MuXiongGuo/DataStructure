#include "vector"
#include "stack"
#include "iostream"
#include "unordered_map"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 暴力枚举 + 回溯 得到路径
class Solution {
public:
    vector<TreeNode*> path_nodes_p, path_nodes_q;
    vector<TreeNode*> res_p, res_q;

    void dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        path_nodes_p.emplace_back(root), path_nodes_q.emplace_back(root);
        if (root == p) {
            res_p = path_nodes_p;
        }
        if (root == q) {
            res_q = path_nodes_q;
        }

        if (root->left) {
            dfs(root->left, p, q);
            path_nodes_q.pop_back(), path_nodes_p.pop_back();
        }
        if (root->right) {
            dfs(root->right, p, q);
            path_nodes_p.pop_back(), path_nodes_q.pop_back();
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        int n = res_p.size() > res_q.size() ? res_q.size() : res_p.size();
        auto res = res_p[0];
        for (int i = 1; i < n; ++i) {
            if (res_p[i] != res_q[i])
                break;
            res = res_p[i];
        }
        return res;
    }
};

// 递归妙用  标准的 从底部开始  类似 110题
class Solution2 {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q)
            return root;
        root->left = lowestCommonAncestor(root->left, p, q);
        root->right = lowestCommonAncestor(root->right, p, q);
        // 此时是公公祖先
        if (root->left && root->right)
            return root;
        // 其余情况
        if (root->left && !root->right)
            return root->left;
        if (!root->left && root->right)
            return root->right;
        // 补一个返回值 要不没法通过
        return nullptr;
    }
};


int main() {
    // [3,5,1,6,2,0,8,null,null,7,4]
    //5
    //4
    auto *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    Solution s;
    auto res = s.lowestCommonAncestor(root, root->left, root->left->right->right);
    cout << res->val << endl;
    return 0;
}