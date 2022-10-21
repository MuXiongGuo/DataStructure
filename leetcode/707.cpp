#include "iostream"

using namespace std;

class MyLinkedList {
public:
    MyLinkedList() {

    }

    int get(int index) {

    }

    void addAtHead(int val) {

    }

    void addAtTail(int val) {

    }

    void addAtIndex(int index, int val) {

    }

    void deleteAtIndex(int index) {

    }

private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode *prev;
        explicit ListNode() : val(0), next(nullptr), prev(nullptr) {};
        explicit ListNode(int a) : val(a), next(nullptr), prev(nullptr) {};
        explicit ListNode(int a, ListNode *n, ListNode *p):val(a), next(n), prev(p) {};
    };
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */