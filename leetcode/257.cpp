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
    vector<string> res;

    void dfs(TreeNode *p, string &s) {
        s += to_string(p->val);
        s += "->";
        if (!p->left && !p->right) {
            s.pop_back(), s.pop_back();
            res.emplace_back(std::move(s));
            return;
        }
        if (p->left && p->right) {
            auto str_copy = s;
            dfs(p->left, s);
            dfs(p->right, str_copy);
        } else if (p->left && !p->right) {
            dfs(p->left, s);
        } else {
            dfs(p->right, s);
        }
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        string start;
        dfs(root, start);
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    Solution s;
    auto res = s.binaryTreePaths(root);
    for (auto &i : res) {
        cout << i << endl;
    }
    return 0;
}