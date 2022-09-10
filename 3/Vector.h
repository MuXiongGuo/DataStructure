//
// Created by 郭慕雄 on 2022/9/8.
//
#ifndef DATASTRUCTUREALGORITHM_VECTOR_H
#define DATASTRUCTUREALGORITHM_VECTOR_H

#include <algorithm>

template<typename Object>
class Vector {
public:
    // 五大函数
    // 0默认构造函数
    explicit Vector(int init = 0) : size(init), capacity(init + SPARE_CAPACITY) {
        objects = new Object[capacity];
    }

    // 1拷贝构造函数
    Vector(const Vector &rhs) : size(rhs.size), capacity(rhs.capacity), objects(nullptr) {
        objects = new Object[capacity];
        for (int i = 0; i < size; ++i) {
            objects[i] = rhs.objects[i];
        }
    }

    // 2拷贝赋值函数
    Vector &operator=(const Vector &rhs) {
        Vector copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    // 3析构函数
    ~Vector() {
        delete[] objects;
    }

    // 4移动构造函数
    Vector(Vector &&rhs) noexcept : size(rhs.size), capacity(rhs.capacity), objects(rhs.objects) {
        rhs.objects = nullptr;
        rhs.size = 0;
        rhs.capacity = 0;
    }

    // 5移动赋值函数
    Vector &operator=(Vector &&rhs) noexcept {
        std::swap(size, rhs.size);
        std::swap(capacity, rhs.capacity);
        std::swap(objects, rhs.objects);
        return *this;
    }

    static const int SPARE_CAPACITY = 16; //静态变量，不能在对象的构造函数中初始化
private:
    int size = 0;
    int capacity = 0;
    Object *objects = nullptr;
};

#endif //DATASTRUCTUREALGORITHM_VECTOR_H
