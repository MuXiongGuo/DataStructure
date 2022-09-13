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
    }

    List(const List &rhs) {
    }

    ~List() {
    }

    List &operator=(const List &rhs) {

    }

    List(List &&rhs) noexcept {
    }

    List &operator=(List &&rhs) noexcept {
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

    iterator insert(iterator itr, const Object &x);

    iterator insert(iterator itr, Object &&x);

    iterator erase(iterator itr);

    iterator erase(iterator from, iterator to);


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
