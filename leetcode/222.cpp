#include "vector"
#include "queue"
#include "stack"
#include "iostream"
#include "unordered_map"
#include "cmath"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 二分查找 加 位运算   非常重要的题目
class Solution {
public:
    bool exist(TreeNode *node, int level, int obj) {
        int bits = 1 << (level-1);
        while (node != nullptr && bits != 0) {
            if (obj & bits) {
                node = node->right;
            } else {
                node = node->left;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }

    int countNodes(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int level = 0;
        auto tmp = root;
        while (tmp->left != nullptr) {
            ++level;
            tmp = tmp->left;
        }
        // 特殊二分  因为这次 不是找匹配 而是 所以小至 指定位置
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (high-low+1)/2+low;
            if (exist(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};