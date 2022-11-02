#include "vector"
#include "queue"
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


// 递归法
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        else if (p == nullptr && q != nullptr)
            return false;
        else if (p != nullptr && q == nullptr)
            return false;
        else if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// 使用 栈
class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk;
        stk.emplace(p), stk.emplace(q);
        while (!stk.empty()) {
            auto q_node = stk.top(); stk.pop();
            auto p_node = stk.top(); stk.pop();
            // 处理空指针
            if ((p_node == nullptr && q_node != nullptr) || (p_node != nullptr && q_node == nullptr))
                return false;
            if (p_node == nullptr && q_node == nullptr);
            else {
                if (p_node->val != q_node->val)
                    return false;
                stk.emplace(p_node->left);
                stk.emplace(q_node->left);
                stk.emplace(p_node->right);
                stk.emplace(q_node->right);
            }
        }
        return true;
    }
};

// 使用 队列
class Solution3 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.emplace(p);que.emplace(q);
        while (!que.empty()) {
            auto p_node = que.front();que.pop();
            auto q_node = que.front();que.pop();
            // 处理空指针
            if ((p_node == nullptr && q_node != nullptr) || (p_node != nullptr && q_node == nullptr))
                return false;
            if (p_node == nullptr && q_node == nullptr);
            else {
                if (p_node->val != q_node->val)
                    return false;
                que.emplace(p_node->left);
                que.emplace(q_node->left);
                que.emplace(p_node->right);
                que.emplace(q_node->right);
            }
        }
        return true;
    }
};


int main() {
    // [1,2]
    //[1,null,2]
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    TreeNode* q = new TreeNode(1);
    q->right = new TreeNode(2);
    Solution2 solution;
    auto ans = solution.isSameTree(p, q);
    return 0;
}


// 使用 队列