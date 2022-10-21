#include "iostream"

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

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* removeElements(ListNode* head, int val) {
        // 处理头部删除特殊情况
        while (head != nullptr && head->val == val) {
            auto tem = head;
            head = head->next;
            delete tem;
        }
        auto head_ans = head;
        while (head != nullptr) {
            // head->next != nullptr 防止 head->next->val访问到空指针时的val，毕竟此时没有这个数值
            // 或者把这个判读啊放到while里面更人性化
            if (head->next != nullptr && head->next->val == val) {
                auto tem = head->next;
                head->next = head->next->next;
                delete tem;
            } else
                head = head->next;
        }
        return head_ans;
    }
};
// 添加一个虚拟节点 使得不用特殊处理头节点
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
//        dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
//        ListNode* cur = dummyHead;
//        while (cur->next != NULL) {
//            if(cur->next->val == val) {
//                ListNode* tmp = cur->next;
//                cur->next = cur->next->next;
//                delete tmp;
//            } else {
//                cur = cur->next;
//            }
//        }
//        head = dummyHead->next;
//        delete dummyHead;
//        return head;
//    }
//};
