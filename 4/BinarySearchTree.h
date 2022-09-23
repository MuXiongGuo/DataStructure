//
// Created by dell on 2022/9/19.
//

#ifndef DATASTRUCTURE_BINARYSEARCHTREE_H
#define DATASTRUCTURE_BINARYSEARCHTREE_H
#include "iostream"
template<typename Comparable>
class BinarySearchTree {
public:
    explicit BinarySearchTree();

    BinarySearchTree(const BinarySearchTree &rhs);

    BinarySearchTree(BinarySearchTree &&rhs);

    ~BinarySearchTree();

    const Comparable &FindMin() const;

    const Comparable &FindMax() const;

    bool Contains(const Comparable &x) const{
        return Contains(x,root);
    }

    bool IsEmpty() const;

    void PrintTree() const;

    void MakeEmpty();

    void Insert(const Comparable &x){
        Insert(x,root);
    }

    void Insert(Comparable &&x){
        Insert(std::move(x),root);
    }

    void Remove(const Comparable &x){
        Remove(x,root);
    }

    BinarySearchTree &operator=(const Comparable &rhs) noexcept;

    BinarySearchTree &operator=(Comparable &&rhs) noexcept;
private:
    struct BinaryNode {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        explicit BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt)
                : element{theElement}, left{lt}, right{rt} {}

        explicit BinaryNode(Comparable &&theElement, BinaryNode *lt, BinaryNode *rt)
                : element{std::move(theElement)}, left{lt}, right{rt} {}
    };

    BinaryNode *root;

    void Insert(const Comparable &x, BinaryNode *&t);
    void Insert(Comparable &&x, BinaryNode *&t);
    void Remove(const Comparable &x, BinaryNode *&t);
    BinaryNode *FindMin(BinaryNode *t) const;
    BinaryNode *FindMax(BinaryNode *t) const;
    bool Contains(const Comparable &x, BinaryNode *t) const{

    }
    void MakeEmpty(BinaryNode *&t);
    void PrintTree(BinaryNode *t, ostream &out) const;
    BinaryNode *Clone(BinaryNode *t) const;
};

#endif //DATASTRUCTURE_BINARYSEARCHTREE_H
