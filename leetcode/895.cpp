#include "bits/stdc++.h"

using namespace std;

//class FreqStack {
//private:
//    int length = 0;
//    unordered_map<int, pair<int, deque<int>>> element_lookup;
//    vector<tuple<int, int, deque<int>>> sort_vec;
//
//    void adjust(tuple<int, int, deque<int>> &a, tuple<int, int, deque<int>> &b) {
//        // 默认a应该 更靠近头部, a的数量和index应该强于b
//        if (get<1>(a) < get<1>(b)) {
//            swap(a, b);
//        } else if (get<1>(a) == get<1>(b) && get<2>(a)[0] < get<2>(b)[0]) {
//            swap(a, b);
//        }
//    }
//
//public:
//    FreqStack() = default;
//
//    void push(int val) {
//        if (element_lookup.find(val) == element_lookup.end()) {
//            // 没有这个元素
//            element_lookup[val] = pair<int, deque<int>>{1, {length}};
//            sort_vec.push_back({val, 1, {length}});
//
//            ++length;
//        }
//    }
//
//    int pop() {
//
//    }
//};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// 每个频率进行一个维护, 毕竟vec弹出还是很容易的
class FreqStack {
private:
    // val, counts
    unordered_map<int, int> element_counts;
    // counts, val
    unordered_map<int, vector<int>> element_sort;
    // 记录 最高位置 因为删除键值对 不太方便
    int height = 0;
public:
    FreqStack() = default;

    void push(int val) {
        ++element_counts[val];
        element_sort[element_counts[val]].emplace_back(val);
        height = max(height, element_counts[val]);
    }

    int pop() {
        int tem = element_sort[height].back();
        element_sort[height].pop_back();
        if (element_sort[height].empty()) {
            --height;
        }
        --element_counts[tem];
        return tem;
    }
};

int main () {
// ["FreqStack","push","push","push","push","push","push","pop","push","pop","push","pop","push","pop","push","pop","pop","pop","pop","pop","pop"]
//[[],[4],[0],[9],[3],[4],[2],[],[6],[],[1],[],[1],[],[4],[],[],[],[],[],[]]
    FreqStack sol;
    sol.push(4);
    sol.push(0);
    sol.push(9);
    sol.push(3);
    sol.push(4);
    sol.push(2);
    cout << sol.pop() << endl;
    sol.push(6);
    cout << sol.pop() << endl;
    sol.push(1);
    cout << sol.pop() << endl;
    sol.push(1);
    cout << sol.pop() << endl;
    sol.push(4);
    cout << sol.pop() << endl;
    cout << sol.pop() << endl;
    cout << sol.pop() << endl;
    cout << sol.pop() << endl;
    cout << sol.pop() << endl;
    cout << sol.pop() << endl;



    return 0;
}
