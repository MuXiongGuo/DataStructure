#include "bits/stdc++.h"

using namespace std;
// 太聪明了 我没想到呀
class MinStack {
private:
    vector<int> stk;
    vector<int> min_stk{INT_MAX};
public:
    /** initialize your data structure here. */
    MinStack() = default;

    void push(int x) {
        stk.emplace_back(x);
        min_stk.emplace_back(std::min(x, min_stk.back()));
    }

    void pop() {
        stk.pop_back();
        min_stk.pop_back();
    }

    int top() {
        return stk.back();
    }

    int min() {
        return min_stk.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */