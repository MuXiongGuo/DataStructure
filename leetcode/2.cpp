#include "iostream"
using namespace std;
//Definition for singly-linked list.
struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * l3_head = new ListNode();
        ListNode * l3 = l3_head;
        ListNode * l3_prev;
        int carry_bit = 0;
        while (l1 != nullptr && l2 != nullptr){
            l3->next = new ListNode();
            int tem = l1->val + l2->val + carry_bit;
            if (tem >= 10){
                carry_bit = 1;
                tem %= 10;
            }else
                carry_bit = 0;
            l3->val = tem;
            l1 = l1->next;
            l2 = l2->next;
            l3_prev = l3;
            l3 = l3->next;
        }
        // case1
        if (l1 == nullptr && l2 == nullptr){
            if (carry_bit == 0){
                delete l3;
                l3_prev->next = nullptr;
            }
            else
                l3->val = carry_bit;
        }
        // case2
        else if (l1 == nullptr){
            l3->val = carry_bit + l2->val;
            if (l3->val >= 10){
                carry_bit = 1;
                l3->val %= 10;
            }else
                carry_bit = 0;
            l3->next = l2->next;

            while (l3->next != nullptr && carry_bit == 1){
                l3->next->val += carry_bit;
                carry_bit = l3->next->val>=10 ? 1:0;
                l3->next->val%=10;
                l3 = l3->next;
            }
            if (l3->next == nullptr && carry_bit == 1)
                l3->next = new ListNode(1);
        }
        // case3
        else if (l2 == nullptr){
            l3->val = carry_bit + l1->val;
            if (l3->val >= 10){
                carry_bit = 1;
                l3->val %= 10;
            }else
                carry_bit = 0;
            l3->next = l1->next;

            while (l3->next != nullptr && carry_bit == 1){
                l3->next->val += carry_bit;
                carry_bit = l3->next->val>=10 ? 1:0;
                l3->next->val%=10;
                l3 = l3->next;
            }
            if (l3->next == nullptr && carry_bit == 1)
                l3->next = new ListNode(1);
        }
        return l3_head;

    }
};

//[2,4,3]
//[5,6,4]

int main(){
    ListNode * l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(9);
    ListNode * l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution s;
    ListNode * l3 = s.addTwoNumbers(l1, l2);
    while (l3 != nullptr){
        cout << l3->val << " ";
        l3 = l3->next;
    }

    return 0;
}