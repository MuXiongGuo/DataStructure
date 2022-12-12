#include "bits/stdc++.h"

using namespace std;

// 树形dp 看官方题解
// 三种状态 借鉴学习
// 对于nullptr特别处理
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    struct status {
        int a, b, c;
    };

    status dfs(TreeNode *root) {
        if (root == nullptr) {
            return {INT_MAX / 2, 0, 0}; // /2是为了 防止做运算的时候溢出了 两个0 表示空节点处不要防止摄像机
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int a = left.c + right.c + 1;
        int b = min(a, min(left.a + right.b, left.b + right.a));
        int c = min(a, left.b + right.b); // 考虑一个三个节点左右两个的树，c的定义是满足子树覆盖且不管根是否的最小，有时候a会比lb+rb小的 注意细节
        return {a, b, c};
    }

    int minCameraCover(TreeNode *root) {
        auto [a, b, c] = dfs(root);
        return b;

    }
};

// 贪心 从底部向上，标记状态 逐渐。。。
// 0无覆盖 1有摄像头 2监控区域
class Solution2 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    int result = 0;

    int dfs(TreeNode *root) {
        if (root == nullptr) {
            // nullptr 设成2 不让其他节点困扰
            return 2;
        }

        int left = dfs(root->left), right = dfs(root->right);
        if (left == 0 || right == 0) {
            ++result;
            return 1;
        } else if (left == 2 && right == 2) {
            return 0;
        } else {
            return 2;
        }
    }

    int minCameraCover(TreeNode *root) {
        if (dfs(root) == 0) {
            ++result;
        }
        return result;
    }
};

