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
    explicit Vector(int init = 0) : size(init), capacity(init + SPARE_CAPACITY) {
        objects = new Object[capacity];
    }


    static const int SPARE_CAPACITY = 16;
private:
    int size = 0;
    int capacity = 0;
    Object *objects = nullptr;
};

#endif //DATASTRUCTUREALGORITHM_VECTOR_H
