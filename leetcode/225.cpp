#include "queue"

using namespace std;


// 使用 move 或者 指针  每次只保持 queue2 为空的  这样逻辑上更舒服
class MyStack {
private:
    queue<int> queue1, queue2;


public:
    MyStack() = default;

    void push(int x) {
        if (queue1.empty())
            queue2.push(x);
        else
            queue1.push(x);
    }

    int pop() {
        if (queue1.empty()) {
            move(queue2, queue1);
            int tem = queue2.front();
            queue2.pop();
            return tem;
        } else {
            move(queue1, queue2);
            int tem = queue1.front();
            queue1.pop();
            return tem;
        }
    }

    int top() {
        if (queue1.empty()) {
            move(queue2, queue1);
            int tem = queue2.front();
            queue2.pop();
            queue1.push(tem);
            return tem;
        } else {
            move(queue1, queue2);
            int tem = queue1.front();
            queue1.pop();
            queue2.push(tem);
            return tem;
        }
    }

    bool empty() {
        return queue1.empty() && queue2.empty();
    }

private:
    void move(queue<int> &q1, queue<int> &q2) {
        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// 只用一个队列就可以
class MyStack2 {
public:
    queue<int> que;
    /** Initialize your data structure here. */
    MyStack() {

    }
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
    }
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = que.size();
        size--;
        while (size--) { // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }
        int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
        que.pop();
        return result;
    }

    /** Get the top element. */
    int top() {
        return que.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};