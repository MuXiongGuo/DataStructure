#include "iostream"
#include "vector"
#include "numeric"

using namespace std;

// 贪心  其实没必要 建立一个组 因为 直接依次遍历就可以了
class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> sequence_of_travel(n);
        for (int i = 0; i < n; ++i) {
            sequence_of_travel[i] = gas[i] - cost[i];
        }
        if (accumulate(sequence_of_travel.begin(), sequence_of_travel.end(), 0) < 0) {
            return -1;
        }
        int start_index = -1; // -1用来表示 无效了
        int cur_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (start_index == -1 && sequence_of_travel[i] >= 0) {
                start_index = i;
                cur_sum = sequence_of_travel[i];
            } else if (start_index != -1) {
                cur_sum += sequence_of_travel[i];
                if (cur_sum < 0)
                    start_index = -1;
            }
        }
        return start_index;
    }
};

// 暴力  利用 while和取余%来模拟循环   值的学习  优雅的暴力
class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < cost.size(); i++) {
            int rest = gas[i] - cost[i]; // 记录剩余油量
            int index = (i + 1) % cost.size();
            while (rest > 0 && index != i) { // 模拟以i为起点行驶一圈
                rest += gas[index] - cost[index];
                index = (index + 1) % cost.size();
            }
            // 如果以i为起点跑一圈，剩余油量>=0，返回该起始位置
            if (rest >= 0 && index == i) return i;
        }
        return -1;
    }
};