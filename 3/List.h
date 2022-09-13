//
// Created by 郭慕雄 on 2022/9/9.
//

#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H

template <typename Object>
class List {
private:
    struct Node{
        Object data;
        Node *prev;
        Node *next;
    };
public:
    class const_iterator{
    public:
        const_iterator():current(nullptr){}
        const Object &operator*() const{
            return retrieve();
        }
        const_iterator &operator++(){
            current=current->next;
            return *this;
        }
        const_iterator operator++(int){
            const_iterator old=*this;
            ++(*this);
            return old;
        }
        const_iterator &operator--(){
            current=current->prev;
            return *this;
        }
        const_iterator operator--(int){
            const_iterator old=*this;
            --(*this);
            return old;
        }
        bool operator==(const const_iterator &rhs) const{
            return current==rhs.current;
        }
        bool operator!=(const const_iterator &rhs) const{
            return !(*this==rhs);
        }
    };
    class iterator:public const_iterator{
};
public:
    List(){
    }
    List(const List &rhs){
    }
    ~List(){
    }
    List &operator=(const List  &rhs){

    }
    List(List &&rhs) noexcept{
    }
    List &operator=(List &&rhs) noexcept{
    }

    iterator begin(){
    }

private:
    int theSize;
    Node *head;
    Node *tail;
    void init(){
        theSize=0;
        head=new Node;
        tail=new Node;
        head->next=tail;
        tail->prev=head;
    }
};
}


#endif //DATASTRUCTURE_LIST_H
