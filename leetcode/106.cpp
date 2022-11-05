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

// 分治
class Solution {
public:
    TreeNode* partition(TreeNode *p, int left_inorder, int right_inorder, int left_postorder, int right_postorder,
                   vector<int> &inorder, vector<int> &postorder) {
        // 处理 递归终结
        if (left_inorder == right_inorder) {
            p->left = new TreeNode(inorder[left_inorder]);
        }

    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

    }
};