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

    void insert(const Comparable &x);
    void insert(Comparable &&x);

    void deleteMin();
    void deleteMin(Comparable &minItem);
    void makeEmpty();
private:
    int currentSize;
    vector<Comparable> array;

    void buildHeap();
    void percolateDown(int hole);
};



#endif //DATASTRUCTURE_BINARYHEAP_H
