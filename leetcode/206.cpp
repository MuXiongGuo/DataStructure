#include "iostream"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *p = nullptr;
        while (head != nullptr) {
            auto tem = new ListNode(head->val, p);
            p = tem;
            auto delete_p = head;
            head = head->next;
            delete delete_p;
        }
        return p;
    }
};