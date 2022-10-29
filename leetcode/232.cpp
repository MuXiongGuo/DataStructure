#include "iostream"
#include "vector"
#include "stack"

using namespace std;

class MyQueue {
public:
    MyQueue() = default;

    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        if (!empty()) {
            if (stack2.empty()) {
                move();
                int tem = stack2.top();
                stack2.pop();
                return tem;
            } else {
                int tem = stack2.top();
                stack2.pop();
                return tem;
            }
        }
        return -1;
    }

    int peek() {
        if (!empty()) {
            if (stack2.empty()) {
                move();
                return stack2.top();
            } else {
                return stack2.top();
            }
        }
        return -1;
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }

    void move() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
private:
    // stack1 use to input
    // stack2 use to output
    stack<int, vector<int> > stack1, stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */