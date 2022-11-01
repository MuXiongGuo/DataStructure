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
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        dfs(root->left);
        dfs(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};

// 官方的 自底部向 上  减少空间消耗
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

作者：LeetCode-Solution
        链接：https://leetcode.cn/problems/invert-binary-tree/solution/fan-zhuan-er-cha-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。