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


class Solution {
public:
    void RemoveNode(TreeNode *&t, int key) {
        if (t == nullptr)
            return;
        else if (t->val > key)
            RemoveNode(t->left, key);
        else if (t->val < key)
            RemoveNode(t->right, key);
        else if (t->left != nullptr && t->right != nullptr) {
            auto tmp = t->right;
            while (tmp->left != nullptr) tmp = tmp->left;  // 找到前驱节点
            t->val = tmp->val;
            RemoveNode(t->right, t->val);  // 很简洁 但是 相当于又要再找这个点一次  可以优化
        } else {
            auto tmp = t;
            t = (t->left == nullptr) ? t->right : t->left;
            delete tmp;
        }
    }

    TreeNode *deleteNode(TreeNode *root, int key) {
        RemoveNode(root, key);
        return root;
    }
};

// 返回节点 删除  递归类型
class Solution2 {
public:

    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key) {
            if (root->left != nullptr && root->right != nullptr) {
                auto old_node = root;
                root = root->right;
                while (root->left != nullptr) root = root->left;
                root->left = old_node->left;
                root = old_node->right;
                delete old_node;
                return root;
            } else {
                auto old_node = root;
                root = root->left == nullptr ? root->right : root->left;
                delete old_node;
                return root;
            }
        }
        if (root->val > key)
            root->left = deleteNode(root->left, key);

        if (root->val < key)
            root->right = deleteNode(root->right, key);

        return root;
    }
};

// 返回节点 删除  迭代类型
class Solution3 {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *cur = root, *curParent = nullptr;
        while (cur && cur->val != key) {
            curParent = cur;
            if (cur->val > key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (!cur) {
            return root;
        }
        if (!cur->left && !cur->right) {
            cur = nullptr;
        } else if (!cur->right) {
            cur = cur->left;
        } else if (!cur->left) {
            cur = cur->right;
        } else {
            TreeNode *successor = cur->right, *successorParent = cur;
            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }
            if (successorParent->val == cur->val) {
                successorParent->right = successor->right;
            } else {
                successorParent->left = successor->right;
            }
            successor->right = cur->right;
            successor->left = cur->left;
            cur = successor;
        }
        if (!curParent) {
            return cur;
        } else {
            if (curParent->left && curParent->left->val == key) {
                curParent->left = cur;
            } else {
                curParent->right = cur;
            }
            return root;
        }
    }
};




// 额外赠送 删除 普通二叉树方法 利用返回值类型 而非 指针引用
class Solution4 {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) return root;
        if (root->val == key) {
            if (root->right == nullptr) { // 这里第二次操作目标值：最终删除的作用
                return root->left;
            }
            TreeNode *cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            swap(root->val, cur->val); // 这里第一次操作目标值：交换目标值其右子树最左面节点。
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};

// 额外赠送 删除 普通二叉树方法 利用迭代
class Solution5 {
private:
    // 将目标节点（删除节点）的左子树放到 目标节点的右子树的最左面节点的左孩子位置上
    // 并返回目标节点右孩子为新的根节点
    // 是动画里模拟的过程
    TreeNode* deleteOneNode(TreeNode* target) {
        if (target == nullptr) return target;
        if (target->right == nullptr) return target->left;
        TreeNode* cur = target->right;
        while (cur->left) {
            cur = cur->left;
        }
        cur->left = target->left;
        return target->right;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        TreeNode* cur = root;
        TreeNode* pre = nullptr; // 记录cur的父节点，用来删除cur
        while (cur) {
            if (cur->val == key) break;
            pre = cur;
            if (cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        if (pre == nullptr) { // 如果搜索树只有头结点
            return deleteOneNode(cur);
        }
        // pre 要知道是删左孩子还是右孩子
        if (pre->left && pre->left->val == key) {
            pre->left = deleteOneNode(cur);
        }
        if (pre->right && pre->right->val == key) {
            pre->right = deleteOneNode(cur);
        }
        return root;
    }
};


// 返回节点 删除  迭代类型  自己的写法  超级完美 自己写的 很简洁
class Solution6 {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *cur = root, *parent_cur = nullptr;
        while (cur && cur->val != key) {
            parent_cur = cur;
            if (cur->val > key)
                cur = cur->left;
            else if (cur->val < key)
                cur = cur->right;
        }
        // not find key
        if (cur == nullptr)
            return root;
        // find
        auto old_node = cur;
        if (cur->left == nullptr) {
            cur = cur->right;
        } else if (cur->right == nullptr) {
            cur = cur->left;
        } else {
            auto successor = cur->right;
            while (successor->left) successor = successor->left;
            successor->left = cur->left;
            cur = cur->right;
        }
        // delete
        if (parent_cur == nullptr) {
            delete old_node;
            return cur;
        } else {
            auto &index = parent_cur->left == old_node ? parent_cur->left:parent_cur->right;
            index = cur;
        }
        delete old_node;
        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(0);
    Solution6 solution6;
    solution6.deleteNode(root, 0);
    return 0;
}
