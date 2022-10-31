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


// 分治递归思想
class Solution {
public:
    TreeNode* listToBST(ListNode* list_head, int size) {
        if (size == 0)
            return nullptr;
        if (size == 1)
            return new TreeNode(list_head->val);
        int mid = size/2;
        auto left_head = list_head;
        while (mid--) list_head = list_head->next;
        auto right_head = list_head->next;
        auto tree_head = new TreeNode(list_head->val);
        tree_head->left = listToBST(left_head, size/2);
        tree_head->right = listToBST(right_head, size-size/2-1);
        return tree_head;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        auto new_head = head;
        while (head != nullptr) {
            ++size;
            head = head->next;
        }
        return listToBST(new_head, size);
    }
};

// 官方 分治  求mid 更规范
class Solution2 {
public:
    ListNode* getMedian(ListNode* left, ListNode* right) {
        ListNode* fast = left;
        ListNode* slow = left;
        while (fast != right && fast->next != right) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode* buildTree(ListNode* left, ListNode* right) {
        if (left == right) {
            return nullptr;
        }
        ListNode* mid = getMedian(left, right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(left, mid);
        root->right = buildTree(mid->next, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
};
