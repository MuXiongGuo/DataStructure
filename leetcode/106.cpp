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
// 如果建立哈希表来 查询 就会线性时间
// 否则 最坏n^2
// 平均 O(nlogn)  主公式 f(n) = f(n/2) + n
class Solution {
public:
    TreeNode *partition(int left_inorder, int right_inorder, int left_postorder, int right_postorder,
                        vector<int> &inorder, vector<int> &postorder) {
        // 处理 递归终结
        if (left_inorder > right_inorder || left_postorder > right_postorder)
            return nullptr;
        // 分治
        int node_val = postorder[right_postorder];
        auto p = new TreeNode(node_val);
        int index_in = find(inorder.begin(), inorder.end(), node_val) - inorder.begin();
        int index_post = left_postorder + index_in - left_inorder - 1;
        p->left = partition(left_inorder, index_in - 1, left_postorder, index_post, inorder, postorder);
        p->right = partition(index_in + 1, right_inorder, index_post + 1, right_postorder - 1, inorder, postorder);
        return p;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return partition(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder);
    }
};

int main() {
    auto s = new Solution();
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    auto root = s->buildTree(inorder, postorder);
    return 0;
}

// 官方的突出一个简洁
class Solution2 {
    int post_idx;
    unordered_map<int, int> idx_map;
public:
    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder){
        // 如果这里没有节点构造二叉树了，就结束
        if (in_left > in_right) {
            return nullptr;
        }

        // 选择 post_idx 位置的元素作为当前子树根节点
        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);

        // 根据 root 所在位置分成左右两棵子树
        int index = idx_map[root_val];

        // 下标减一
        post_idx--;
        // 构造右子树
        root->right = helper(index + 1, in_right, inorder, postorder);
        // 构造左子树
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 从后序遍历的最后一个元素开始
        post_idx = (int)postorder.size() - 1;

        // 建立（元素，下标）键值对的哈希表
        int idx = 0;
        for (auto& val : inorder) {
            idx_map[val] = idx++;
        }
        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }
};

//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solution/cong-zhong-xu-yu-hou-xu-bian-li-xu-lie-gou-zao-14/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 官方的迭代法
class Solution3 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return nullptr;
        stack<TreeNode*> stk;
        auto root = new TreeNode(postorder.back());
        stk.emplace(root);
        int inorder_index = int(inorder.size()-1);
        for (int i = int(inorder.size()-2); i >= 0; --i) {
            int post_value = postorder[i];
            auto node = stk.top();
            if (node->val != inorder[inorder_index]) {
                node->right = new TreeNode(post_value);
                stk.emplace(node->right);
            } else {
                while (!stk.empty() && stk.top()->val == inorder[inorder_index]) {
                    node = stk.top();
                    stk.pop();
                    --inorder_index;
                }
                node->left = new TreeNode(post_value);
                stk.emplace(node->left);
            }
        }
        return root;
    }
};

