#include "vector"
#include "queue"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if (root != nullptr) que.emplace(root);
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                auto node = que.front();
                if (node->left) que.emplace(node->left);
                if (node->right) que.emplace(node->right);
                que.pop();
                if (n == 0)
                    res.emplace_back(node->val);
            }
        }
        return res;
    }
};

//   深度优先  利用递归
class Solution {
public:
    //深度优先遍历
    vector<int> ret;
    void _rightView(TreeNode* node, int depth) {
        if (node == nullptr) return;
        if (ret.size() == depth) ret.emplace_back(node->val);
        if (node->right) _rightView(node->right, depth + 1);
        if (node->left) _rightView(node->left, depth + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        _rightView(root, 0);
        return ret;
    }
};