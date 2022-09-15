//
// Created by 郭慕雄 on 2022/9/15.
//
// 实现列表L1和L2的交集与并集
#include "iostream"
#include "list"

using namespace std;

template<typename Object>
list<Object> InterSection(const list<Object> &l1, const list<Object> &l2) {
    list<Object> intersect;
    auto it1 = l1.begin();
    auto it2 = l2.begin();
    while (it1 != l1.end() && it2 != l2.end()) {
        if (*it1 == *it2) {
            intersect.push_back(*it1);
            ++it1, ++it2;
        } else if (*it1 < *it2)
            ++it1;
        else
            ++it2;
    }
    return intersect;
}

template<typename Object>
list<Object> Union1(const list<Object> &l1, const list<Object> &l2) {
    list<Object> union_set;
    auto it1 = l1.begin();
    auto it2 = l2.begin();
    while (it1 != l1.end() && it2 != l2.end()) {
        if (*it1 == *it2) {
            union_set.push_back(*it1);
            ++it1, ++it2;
        } else if (*it1 < *it2) {
            union_set.push_back(*it1);
            ++it1;
        } else {
            union_set.push_back(*it2);
            ++it2;
        }
    }
    while (it1 != l1.end()) {
        union_set.push_back(*it1);
        ++it1;
    }
    while (it2 != l2.end()) {
        union_set.push_back(*it2);
        ++it2;
    }
    return union_set;
}

// 自己写的版本
template<typename Object>
list<Object> Union2(const list<Object> &l1, const list<Object> &l2) {
    list<Object> union_set;
    auto it1 = l1.begin();
    auto it2 = l2.begin();
    while (it1 != l1.end() || it2 != l2.end()) {
        if (it1 != l1.end() && it2 != l2.end() && *it1 == *it2) {
            union_set.push_back(*it1);
            ++it1, ++it2;
        } else if (it1 != l1.end() && (it2 == l2.end() || *it1 < *it2)) {
            union_set.push_back(*it1);
            ++it1;
        } else {
            union_set.push_back(*it2);
            ++it2;
        }
    }
    return union_set;
}

int main() {
    list<int> l2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> l1 = {1, 3, 5, 7, 9, 21};
    list<int> intersect = InterSection(l1, l2);
    list<int> union_set = Union1(l1, l2);
    list<int> union_set2 = Union2(l1, l2);
    for (auto &i: intersect) {
        cout << i << " ";
    }
    cout << endl;
    for (auto &i: union_set) {
        cout << i << " ";
    }
    cout << endl;
    for (auto &i: union_set2) {
        cout << i << " ";
    }
    return 0;
}