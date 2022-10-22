#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 虚拟头节点 很好用
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return head;
        auto new_head = new ListNode(0, head);
        auto p = new_head;
        while (p->next != nullptr && p->next->next != nullptr) {
            auto p1 = p->next, p2 = p->next->next, p3 = p->next->next->next;
            p->next = p2;
            p1->next = p3;
            p2->next = p1;
            p = p1;
        }
        return new_head->next;
    }
};
