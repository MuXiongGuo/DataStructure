//
// Created by 郭慕雄 on 2022/9/9.
//

#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H

#include <iostream>

template<typename Object>
class List {
private:
    struct Node {
        Object data;
        Node *prev;
        Node *next;

        explicit Node(const Object &d = Object(), Node *p = nullptr, Node *n = nullptr) : data(d), prev(p), next(n) {}

        explicit Node(Object &&d, Node *p = nullptr, Node *n = nullptr) : data(std::move(d)), prev(p), next(n) {}

    };

public:
    class const_iterator {
    public:
        const_iterator() : current{nullptr} {}

        const Object &operator*() const {
            return retrieve();
        }

        const_iterator &operator++() {
            current = current->next;
            return *this;
        }

        // 针对后缀++ int没有实际意义 仅仅是区分前缀和后缀
        const_iterator operator++(int) {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator &rhs) {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator &rhs) {
            return !(*this == rhs);
        }

    protected:
        Node *current;

        Object &retrieve() const {
            return current->data;
        }

        const_iterator(Node *p) : current{p} {} // 只有List能用这个构造函数

        friend class List<Object>;
    };

    class iterator : public const_iterator {
    public:
        iterator(){}

        Object & operator*(){
            return const_iterator::retrieve();
        }

        Object & operator*()const{
            return const_iterator::operator*();
        }

        iterator & operator++(){
            this->current = this->current->next;
            return *this;
        }

        iterator operator++(int){
            iterator old = *this;
            ++(*this);
            return old;
        }

        protected:
            iterator(Node *p):const_iterator(p){}
            friend class List<Object>;
    };

public:
    List() {
        init();
    }

    List(std::initializer_list<Object> &&il) {
        init();
        for (auto &&x:il)
            push_back(std::move(x));
    }

    List(const List &rhs) {
        init();
        for (auto &x:rhs)
            push_back(x);
    }

    ~List() {
        clear();
        delete head;
        delete tail;
    }

    // 正常逻辑是先清空再拷贝, 但是代码没法复用了, 造一个空的直接换, 最后内存释放交给析构函数   注意swap的是*this this是指针 应该直接交换对象
    List &operator=(const List &rhs) {
        List copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    List(List &&rhs) noexcept: theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail} {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }

    List &operator=(List &&rhs) noexcept {
//        std::swap(*this, rhs);   不能这样写 因为以后会用到 则会死循环 std::swap(*this, rhs);这个会调用自己
        std::swap(theSize, rhs.theSize);
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        return *this;
    }

    iterator begin() {
        return head->next;
    }

    const_iterator begin() const {
        return head->next;
    }

    iterator end() {
        return tail;
    }

    const_iterator end() const {
        return tail;
    }

    int size() const {
        return theSize;
    }

    bool empty() const {
        return size() == 0;
    }

    void clear() {
        while (!empty())
            pop_front();
    }

    Object &front() {
        return *begin();
    }

    const Object &front() const {
        return *begin();
    }

    Object &back() {
        return *--end();
    }

    const Object &back() const {
        return *--end();
    }

    void push_front(const Object &x) {
        insert(begin(), x);
    }

    void push_front(Object &&x) {
        insert(begin(), std::move(x));
    }

    void push_back(const Object &x) {
        insert(end(), x);
    }

    void push_back(Object &&x) {
        insert(end(), std::move(x));
    }

    void pop_front() {
        erase(begin());
    }

    void pop_back() {
        erase(--end());
    }

    iterator insert(iterator itr, const Object &x){
        Node *p = itr.current;
        theSize++;
        return p->prev = p->prev->next = new Node(x, p->prev, p);
    }

    iterator insert(iterator itr, Object &&x){
        Node *p = itr.current;
        theSize++;
        return p->prev = p->prev->next = new Node(std::move(x), p->prev, p);
    }

    iterator erase(iterator itr){
        Node *p = itr.current;
        iterator return_val = iterator{p->next};
        theSize--;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        return return_val;
    }

    iterator erase(iterator from, iterator to){
        for(iterator it = from; it != to;)
            it = erase(it);
        return to;
    }


private:
    int theSize;
    Node *head;
    Node *tail;

    void init() {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
};

#endif //DATASTRUCTURE_LIST_H
