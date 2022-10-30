#include "vector"
#include "queue"

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (root != nullptr) que.emplace(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            while (size--) {
                tmp.emplace_back(que.front()->val);
                if (que.front()->left) que.emplace(que.front()->left);
                if (que.front()->right) que.emplace(que.front()->right);
                que.pop();
            }
            res.emplace_back(std::move(tmp));
        }
        return res;
    }
};