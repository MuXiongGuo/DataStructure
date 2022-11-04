#include "vector"
#include "queue"
#include "stack"
#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 暴力搜索
class Solution {
public:
    bool check(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot)
            return true;
        if ((!root && subRoot) || (root && !subRoot) || (root->val != subRoot->val))
            return false;
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }

    bool dfs (TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr)
            return false;
        return check(root, subRoot) || dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        return dfs(root, subRoot);
    }
};

// kmp算法
class Solution2 {
public:
    vector<int> rootOrder, subRootOrder;

    void getOrder(TreeNode *p, vector<int> &order) {
        if (p == nullptr) {
            order.emplace_back(INT_MIN);
            return;
        }
        order.emplace_back(p->val);
        getOrder(p->left, order);
        getOrder(p->right, order);
    }

    void getNext(int next[], const vector<int> &s) {
        // 初始化
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); ++i) {
            // !=
            while (j>0 && s[j] != s[i]) j = next[j-1];
            // ==
            if (s[i] == s[j])
                ++j;
            next[i] = j;
        }
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        getOrder(root, rootOrder);
        getOrder(subRoot, subRootOrder);
        int next[subRootOrder.size()];
        getNext(next, subRootOrder);
        int j = 0;
        for (int i = 0; i < rootOrder.size(); ++i) {
            while (j>0 && rootOrder[i] != subRootOrder[j]) j = next[j-1];
            if (rootOrder[i] == subRootOrder[j])
                ++j;
            if (j == subRootOrder.size())
                return true;
        }
        return false;
    }
};


// 哈希树
class Solution3 {
public:
    static constexpr int MAX_N = 1000 + 5;
    static constexpr int MOD = int(1E9) + 7;

    bool vis[MAX_N];
    int p[MAX_N], tot;
    void getPrime() {
        vis[0] = vis[1] = 1; tot = 0;
        for (int i = 2; i < MAX_N; ++i) {
            if (!vis[i]) p[++tot] = i;
            for (int j = 1; j <= tot && i * p[j] < MAX_N; ++j) {
                vis[i * p[j]] = 1;
                if (i % p[j] == 0) break;
            }
        }
    }

    struct Status {
        int f, s; // f 为哈希值 | s 为子树大小
        Status(int f_ = 0, int s_ = 0)
                : f(f_), s(s_) {}
    };

    unordered_map <TreeNode *, Status> hS, hT;

    void dfs(TreeNode *o, unordered_map <TreeNode *, Status> &h) {
        h[o] = Status(o->val, 1);
        if (!o->left && !o->right) return;
        if (o->left) {
            dfs(o->left, h);
            h[o].s += h[o->left].s;
            h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD;
        }
        if (o->right) {
            dfs(o->right, h);
            h[o].s += h[o->right].s;
            h[o].f = (h[o].f + (179LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD;
        }
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        getPrime();
        dfs(s, hS);
        dfs(t, hT);

        int tHash = hT[t].f;
        for (const auto &[k, v]: hS) {
            if (v.f == tHash) {
                return true;
            }
        }

        return false;
    }
};

作者：LeetCode-Solution
        链接：https://leetcode.cn/problems/subtree-of-another-tree/solution/ling-yi-ge-shu-de-zi-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。