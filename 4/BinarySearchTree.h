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

    void Insert(const Comparable &x, BinaryNode *&t){
        if (t == nullptr)
            t = new BinaryNode(x, nullptr, nullptr);
        else if (t->element > x)
            Insert(x, t->left);
        else
            Insert(x, t->right);
        // 不处理重复元
    }
    void Insert(Comparable &&x, BinaryNode *&t){
        if (t == nullptr)
            t = new BinaryNode(std::move(x), nullptr, nullptr);
        else if (t->element > x)
            Insert(std::move(x), t->left);
        else
            Insert(std::move(x), t->right);
        // 不处理重复元
    }
    void Remove(const Comparable &x, BinaryNode *&t){
        if (t == nullptr)
            return;
        if (t->element > x)
            Remove(x, t->left);
        else if (t->element < x)
            Remove(x, t->right);
        else{
            if (t->left == nullptr){
                auto tem = t;
                t = t->right;
                delete(tem);
            }
            else if (t->right == nullptr){
                auto tem = t;
                t = t->left;
                delete(tem);
            }
            else{
                t->element = FindMin(t->right)->element;
                Remove(t->element, t->right);
            }
        }
    }
    BinaryNode *FindMin(BinaryNode *t) const{
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        else if (t->left != nullptr)
            return FindMin(t->left);
    }
    BinaryNode *FindMax(BinaryNode *t) const{
        if (t == nullptr)
            return nullptr;
        while (t->right != nullptr){
            t = t->right;
        }
        return t;
    }
    bool Contains(const Comparable &x, BinaryNode *t) const{
        if (t == nullptr)
            return false;
        // 按道理说可以把判断相等放最后，因为这一步最不可能发生
        if (x == t->element)
            return true;
        else if (x < t->element)
            return Contains(x, t->left);
        else
            return Contains(x, t->right);
    }
    void MakeEmpty(BinaryNode *&t);
    void PrintTree(BinaryNode *t, ostream &out) const;
    BinaryNode *Clone(BinaryNode *t) const;
};

#endif //DATASTRUCTURE_BINARYSEARCHTREE_H
