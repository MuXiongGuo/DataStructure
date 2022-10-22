#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 双指针 只要遍历一次  更牛一些
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 先确定size
        auto p = head;
        int size = 0;
        while (p != nullptr) {
            ++size;
            p = p->next;
        }
        int index = size - n;
        // 虚拟头节点
        auto new_head = new ListNode(0, head);
        auto p0 = new_head;
        while (index != 0)
            p0 = p0->next, --index;
        // 开始删除
        auto tem = p0->next;
        p0->next = p0->next->next;
        delete tem;
        return new_head->next;
    }
};