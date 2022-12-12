#include "bits/stdc++.h"

using namespace std;

class CQueue {
private:
    vector<int> a, b;
public:
    CQueue() = default;

    void appendTail(int value) {
        a.push_back(value);
    }

    int deleteHead() {
        int res = -1;
        if (a.empty() && b.empty()) { return -1;}
        if (b.empty()) {
            b.assign(a.rbegin(), a.rend());
            a.clear();
        }
        res = b.back();
        b.pop_back();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */