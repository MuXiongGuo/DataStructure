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


// 广度
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        if (root != nullptr) que.emplace(root);
        while (!que.empty()) {
            int n = que.size();
            double count = n, sum = 0;
            while (n--) {
                auto node = que.front();
                que.pop();
                if (node->left) que.emplace(node->left);
                if (node->right) que.emplace(node->right);
                sum += node->val;
            }
            res.emplace_back(sum/count);
        }
        return res;
    }
};

// 深度   vector 的扩容技巧  根据 vector的size和 当前深度的比较  来确定是否扩容
class Solution2 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sums;
        vector<int> counts;
        dfs(sums, counts, 0, root);
        for (int i = 0; i < sums.size(); ++i)
            sums[i]/=counts[i];
        return sums;
    }

    void dfs(vector<double> &sums, vector<int> &counts, int levels, TreeNode* root) {
        if (root == nullptr) return;
        if (levels < sums.size()) {
            sums[levels] += root->val;
            ++counts[levels];
        } else {
            sums.emplace_back(root->val);
            counts.emplace_back(1);
        }
        dfs (sums, counts, levels+1, root->left);
        dfs (sums, counts, levels+1, root->right);
    }
};