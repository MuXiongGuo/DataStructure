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
    explicit HashTable(unsigned int size = 101) : current_size{0}, theLists{size}{
    }

    bool contains(const HashedObj &x) const;

    void MakeEmpty();

    bool Insert(const HashedObj &x);

    bool Insert(HashedObj &&x);

    bool Remove(const HashedObj &x);

private:
    vector<list<HashedObj>> theLists;
    int current_size;

    void rehash();
    size_t myhash(const HashedObj &x) const{
        static hash<HashedObj> hf;
        return hf(x)%theLists.size();
    }
};

template<typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj &x) const {
    return false;
}

template<typename Key>
class hash{
public:
    size_t operator()(const Key &k) const{
        static hash<Key> hf;
        return hf(k);
    }
};


class Employee{
public:
    const string &GetName() const{
        return name;
    }

    bool operator==(const Employee &rhs) const{
        return name==rhs.name;
    }
    bool operator!=(const Employee &rhs) const{
        return !(rhs==*this);
    }

private:
    string name;
    double salary;
    int seniority;
};





#endif //DATASTRUCTURE_HASHTABLE_H
