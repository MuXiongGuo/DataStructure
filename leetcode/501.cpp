#include "vector"
#include "stack"
#include "iostream"
#include "unordered_map"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 遍历 哈希表 线性时间 但空间是额外的
class Solution {
public:
    unordered_map<int, int> lookup;

    void dfs(TreeNode *root) {
        if (root == nullptr)
            return;
        ++lookup[root->val];
        dfs(root->left);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode *root) {
        dfs(root);
        int max = -1;
        vector<int> res;
        for (const auto &a: lookup) {
            if (a.second > max) {
                res.clear();
                max = a.second;
                res.emplace_back(a.first);
            } else if (a.second == max) {
                res.emplace_back(a.first);
            }
        }
        return res;
    }
};


// 线性时间  递归的时间不考虑
class Solution2 {
public:
    vector<int> res;
    int max_occur_times = -1;
    int occur_times = 0;
    TreeNode *pre = nullptr;

    void dfs(TreeNode *root) {
        if (root == nullptr)
            return;
        dfs(root->left);
        if (pre == nullptr || root->val == pre->val) {
            ++occur_times;
        } else if (root->val != pre->val) {
            occur_times = 1;
        }
        pre = root;
        if (occur_times == max_occur_times) {
            res.emplace_back(pre->val);
        } else if (occur_times > max_occur_times) {
            res.clear();
            res.emplace_back(pre->val);
            max_occur_times = occur_times;
        }
        dfs(root->right);
    }

    vector<int> findMode(TreeNode *root) {
        dfs(root);
        return res;
    }
};

// 官方的  代码复用  学习一下吧
class Solution3 {
public:
    vector<int> answer;
    int base, count, maxCount;

    void update(int x) {
        if (x == base) {
            ++count;
        } else {
            count = 1;
            base = x;
        }
        if (count == maxCount) {
            answer.push_back(base);
        }
        if (count > maxCount) {
            maxCount = count;
            answer = vector<int> {base};
        }
    }

    void dfs(TreeNode* o) {
        if (!o) {
            return;
        }
        dfs(o->left);
        update(o->val);
        dfs(o->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return answer;
    }
};

//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/find-mode-in-binary-search-tree/solution/er-cha-sou-suo-shu-zhong-de-zhong-shu-by-leetcode-/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// 我自己写的 更快一些 但也 不简洁一些
class Solution4 {
public:
    vector<int> res;
    int max_occur_times = -1;
    int occur_times = 0;
    TreeNode *pre = nullptr;

    void dfs(TreeNode *root) {
        if (root == nullptr)
            return;
        dfs(root->left);
        if (pre == nullptr || root->val == pre->val) {
            ++occur_times;
        } else if (root->val != pre->val) {
            if (occur_times == max_occur_times) {
                res.emplace_back(pre->val);
            } else if (occur_times > max_occur_times) {
                res.clear();
                res.emplace_back(pre->val);
                max_occur_times = occur_times;
            }
            occur_times = 1;
        }
        pre = root;
        dfs(root->right);
    }

    vector<int> findMode(TreeNode *root) {
        dfs(root);
        if (occur_times == max_occur_times)
            res.emplace_back(pre->val);
        else if (occur_times > max_occur_times) {
            res.clear();
            res.emplace_back(pre->val);
        }
        return res;
    }
};