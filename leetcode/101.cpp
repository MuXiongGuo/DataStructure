#include "vector"
#include "stack"

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
    vector<int> pre;
    vector<int> post;
    void preTraversal (TreeNode* root) {
        if (root == nullptr) {
            pre.emplace_back(200);
            return;
        }
        pre.emplace_back(root->val);
        preTraversal(root->left);
        preTraversal(root->right);
    }

    void postTraversal (TreeNode* root) {
        if (root == nullptr) {
            post.emplace_back(200);
            return;
        }
        post.emplace_back(root->val);
        postTraversal(root->right);
        postTraversal(root->left);
    }

    bool isSymmetric(TreeNode* root) {
        preTraversal(root);
        postTraversal(root);
        return pre == post;
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {

    }
};



// 双指针 递归  想不到
class Solution {
public:
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

作者：LeetCode-Solution
        链接：https://leetcode.cn/problems/symmetric-tree/solution/dui-cheng-er-cha-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    Solution solution;
    solution.isSymmetric(root);
    return 0;
}