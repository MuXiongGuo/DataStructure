#include "iostream"

using namespace std;

class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode *prev;

        explicit ListNode() : val(0), next(nullptr), prev(nullptr) {};

        explicit ListNode(int a) : val(a), next(nullptr), prev(nullptr) {};

        explicit ListNode(int a, ListNode *n, ListNode *p) : val(a), next(n), prev(p) {};
    };
public:
    MyLinkedList() {
        init();
    }

    int get(int index) {
        return getIndex(index) == nullptr ? -1 : getIndex(index)->val;
    }

    void addAtHead(int val) {
        insertElement(head->next, val);
    }

    void addAtTail(int val) {
        insertElement(tail, val);
    }

    void addAtIndex(int index, int val) {
        if (index > the_size)
            return;
        else if (index <= 0)
            addAtHead(val);
        else if (index == the_size)
            addAtTail(val);
        else {
            auto p = getIndex(index);
            insertElement(p, val);
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= the_size)
            return;
        else {
            auto p = getIndex(index);
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            --the_size;  // --size 不能放在前面 否则影响 get_index 找相应指针
        }
    }

     ListNode* getIndex(int index) {
        // 更牛一点的 可以判断 size index位置，选择从前往后找 还是 从后往前找
        if (index >= the_size || index < 0)
            return nullptr;
        auto tem = head;
        while (index >= 0) {
            tem = tem->next;
            --index;
        }
        return tem;
    }

    void insertElement(ListNode* p, int val) {
        // 插入的p的前面，不检查是否合理
        ++the_size;
        p->prev = p->prev->next = new ListNode(val, p, p->prev);
    }
public:
    ListNode *head;
    ListNode *tail;
    int the_size;

    void init() {
        head = new ListNode();
        tail = new ListNode();
        the_size = 0;
        head->next = tail;
        tail->prev = head;
    }
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
int main() {
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(1);
    cout << obj->get(0) << endl;
    obj->deleteAtIndex(0);
    return 0;
}