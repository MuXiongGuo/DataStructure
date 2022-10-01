/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> myGenerate(int low, int high){
        if (low > high)
            return vector<TreeNode*>{nullptr};
        vector<TreeNode*> all_tree_nodes;
        for (int i = low; i <= high; ++i){
            // root 定义应在for循环里 因为每次都是一颗新的树根 而不是共用一个树根  重复的对象 会怎么样呢
            TreeNode *root = new TreeNode(i);
            vector<TreeNode*>left = myGenerate(low, i-1);
            vector<TreeNode*>right = myGenerate(i+1, high);
            for (auto &l : left)
                for (auto &r: right){
                    root->left = l;
                    root->right = r;
                    all_tree_nodes.push_back(root);
                }
        }
        return all_tree_nodes;
    }

    vector<TreeNode*> generateTrees(int n) {
        return myGenerate(1,n);
    }
};