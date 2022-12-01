#include "iostream"
#include "vector"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 放到 表里
class Solution {
public:
    void DeleteNode(vector<ListNode *> &vec, int i) {
        auto pre = vec[i - 1], cur = vec[i];
        pre->next = cur->next;
        delete cur;
    }

    ListNode *removeNodes(ListNode *head) {
        ListNode *head_new = new ListNode(0, head);
        vector<ListNode *> vec;
        ListNode *p = head_new;
        while (p) {
            vec.emplace_back(p);
            p = p->next;
        }
        int max_val = INT_MIN;
        for (int i = vec.size() - 1; i >= 1; --i) {
            if (vec[i]->val >= max_val) {
                max_val = vec[i]->val;
            } else {
                DeleteNode(vec, i);
            }
        }
        return head_new->next;
    }
};

// 用递归 从最后面开始 处理, 删除节点可以利用 返回下个节点来做到, 倒着处理 最适合递归了
// 好题目
class Solution2 {
public:

    ListNode *removeNodes(ListNode *head) {
        // 处理空指针
        if (!head->next) { return head; }
        // 靠这句 做到了 从尾部处理
        auto p_node = removeNodes(head->next);
        // 删除
        if (p_node->val > head->val) {
            delete head;
            return p_node;
        }
        // 不删除
        head->next = p_node;
        // 释放内存

        return head;
    }
};