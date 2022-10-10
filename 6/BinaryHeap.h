#ifndef DATASTRUCTURE_BINARYHEAP_H
#define DATASTRUCTURE_BINARYHEAP_H

#include "vector"

using namespace std;

template <typename Comparable>
class BinaryHeap{
public:
    explicit BinaryHeap(int capacity);
    explicit BinaryHeap(const vector<Comparable> &items);

    bool isEmpty() const;
    const Comparable & findMin() const;

    void insert(const Comparable &x){
        if (currentSize == array.size()-1)
            array.resize(array.size()*2);
        int hole = ++currentSize;
        Comparable copy = x;
        array[0] = std::move(x);
        for (; x<array[hole/2]; hole/=2)
            array[hole] = std::move(array[hole]);
        array[hole] = std::move(array[0]);
    }
    void insert(Comparable &&x);

    void deleteMin(){
        if (isEmpty())
            throw UnderflowException{};
        array[1] = std::move(array[currentSize--]);
        percolateDown(1);
    }
    void deleteMin(Comparable &minItem);
    void makeEmpty();
private:
    int currentSize;
    vector<Comparable> array;

    void buildHeap();
    void percolateDown(int hole){
        int child;
        Comparable temp = std::move(array[hole]);
        for (; hole*2 <= currentSize; hole = child){
            child = hole*2;
            if (child != currentSize && array[child+1] < array[child])
                ++child;
            if(array[child] < temp)
                array[hole] = std::move(array[child]);
            else
                break;
        }
        array[hole] = std::move(temp);
    }
};



#endif //DATASTRUCTURE_BINARYHEAP_H
