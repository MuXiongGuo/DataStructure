//
// Created by dell on 2022/9/26.
//

#ifndef DATASTRUCTURE_HASHTABLE_H
#define DATASTRUCTURE_HASHTABLE_H
#include "list"
#include "iostream"
#include "vector"

using namespace std;

template<typename HashedObj>
class HashTable {
public:
    explicit HashTable(int size = 101);

    bool contains(const HashedObj &x) const;

    void MakeEmpty();

    bool Insert(const HashedObj &x);

    bool Insert(HashedObj &&x);

    bool Remove(const HashedObj &x);

private:
    vector<list<HashedObj>> theLists;
    int current_size;

    void rehash();
    size_t myhash(const HashedObj &x) const;
};



#endif //DATASTRUCTURE_HASHTABLE_H
