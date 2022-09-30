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
    explicit Vector(int init = 0) : size_(init), capacity_(init + kSPARE_CAPACITY) {
        objects_ = new Object[capacity_];
    }

    explicit Vector(const std::initializer_list<Object> &list) : size_(list.size()), capacity_(list.size() + kSPARE_CAPACITY) {
        objects_ = new Object[capacity_];
        std::copy(list.begin(), list.end(), objects_);
    }

    // 1拷贝构造函数
    Vector(const Vector &rhs) : size_(rhs.size_), capacity_(rhs.capacity_), objects_(nullptr) {
        objects_ = new Object[capacity_];
        for (int i = 0; i < size_; ++i) {
            objects_[i] = rhs.objects_[i];
        }
    }

    // 2拷贝赋值函数
    Vector &operator=(const Vector &rhs) {
        if (this==&rhs) return *this; // 防止自赋值
        Vector copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    // 3析构函数
    ~Vector() {
        delete[] objects_;
    }

    // 4移动构造函数
    Vector(Vector &&rhs) noexcept : size_(rhs.size_), capacity_(rhs.capacity_), objects_(rhs.objects_) {
        rhs.objects_ = nullptr;
        rhs.size_ = 0;
        rhs.capacity_ = 0;
    }

    // 5移动赋值函数
    Vector &operator=(Vector &&rhs) noexcept {
        std::swap(size_, rhs.size_);
        std::swap(capacity_, rhs.capacity_);
        std::swap(objects_, rhs.objects_);
        return *this;
    }

    void reserve(int new_capacity){
        if (new_capacity < capacity_)
            return;
        auto *new_array = new Object[new_capacity];
        for (int i = 0; i < size_; ++i)
            new_array[i] = std::move(objects_[i]);
        capacity_ = new_capacity;
        std::swap(objects_, new_array);
        delete [] new_array;
    }

    void resize(int new_size){
        if (new_size > capacity_)
            reserve(new_size * 2);
        size_ = new_size;
    }

    // 两种[]重载 适应不同情况，const和非const，对应修改和访问
    Object &operator[](int index){
        return objects_[index];
    }
    // 第一个const表示返回的对象不允许修改，第二个const修饰this，引起重载
    const Object &operator[](int index) const{
        return objects_[index];
    }

    bool empty() const{
        return size_ == 0;
    }

    int size() const{
        return size_;
    }

    int capacity() const{
        return capacity_;
    }

    void push_back(const Object &x){
        if (size_ == capacity_)
            reserve(2 * capacity_ + 1);
        objects_[size_++] = x;
    }

    void push_back(Object &&x){
        if (size_ == capacity_)
            reserve(2 * capacity_ + 1);
        objects_[size_++] = std::move(x);
    }

    void pop_back(){
        --size_;
    }

    const Object &back() const{
        return objects_[size_ - 1];
    }

    using iterator = Object *;
    using const_iterator = const Object *;

    iterator begin(){
        return &objects_[0];
    }
    // 基于const的重载，函数的返回类型不能用来作为重载的标准
    const_iterator begin() const{
        return &objects_[0];
    }
    iterator end(){
        return &objects_[size_]; // tail next to last
    }

    const_iterator end() const{
        return &objects_[size_];
    }

    static const int kSPARE_CAPACITY = 16; //静态变量，不能在对象的构造函数中初始化
private:
    int size_ = 0;
    int capacity_ = 0;
    Object *objects_ = nullptr;
};

#endif //DATASTRUCTUREALGORITHM_VECTOR_H
