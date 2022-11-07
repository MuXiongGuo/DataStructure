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
    unordered_map<int, int> lookup;

    TreeNode *
    Partition(int left_pre, int right_pre, int left_in, int right_in, vector<int> &preorder, vector<int> &inorder) {
        if (left_pre > right_pre || left_in > right_in)
            return nullptr;
        auto p = new TreeNode(preorder[left_pre]);
        int in_index = lookup[p->val];
        int pre_index = left_pre + in_index - left_in;
        p->left = Partition(left_pre + 1, pre_index, left_in, in_index - 1, preorder, inorder);
        p->right = Partition(pre_index + 1, right_pre, in_index + 1, right_in, preorder, inorder);
        return p;
    }


    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            lookup[inorder[i]] = i;
        return Partition(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }
};

// 官方版
class Solution2 {
public:
    unordered_map<int, int> lookup;
    int preindex = 0;

    TreeNode *Partition(int left, int right, vector<int> &preorder, vector<int> &inorder) {
        if (left > right)
            return nullptr;

        auto p = new TreeNode(preorder[preindex++]);
        int index = lookup[p->val];
        p->left = Partition(left, index-1, preorder, inorder);
        p->right = Partition(index+1, right, preorder, inorder);
        return p;
    }


    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            lookup[inorder[i]] = i;
        return Partition(0, preorder.size() - 1, preorder, inorder);
    }
};

// 迭代版
class Solution3 {
public:

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return nullptr;
        stack<TreeNode*> stk;
        int in_index = 0;
        auto root = new TreeNode(preorder[0]);
        stk.emplace(root);
        for (int i = 1; i < preorder.size(); ++i) {
            int pre_value = preorder[i];
            auto node = stk.top();
            if (node->val != inorder[in_index]) {
                node->left = new TreeNode(pre_value);
                stk.emplace(node->left);
            } else {
                while (!stk.empty() && stk.top()->val == inorder[in_index]) {
                    node = stk.top();
                    stk.pop();
                    ++in_index;
                }
                node->right = new TreeNode(pre_value);
                stk.emplace(node->right);
            }
        }
        return root;
    }
};