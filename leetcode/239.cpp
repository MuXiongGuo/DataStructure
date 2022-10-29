#include "string"
#include "stack"
#include "vector"
#include "iostream"
#include "deque"
#include "queue"

using namespace std;


// 1. 单调队列
class Solution {
public:
    class MyQueue { // 从大到小
    public:
        deque<int> que;
        void pop(int value) {
            if (!que.empty() && que.front() == value)
                que.pop_front();
        }

        void push(int value) {
            while (!que.empty() && que.back() < value) {
                que.pop_back();  // 左边的最大 所以 从后面开始弹出
            }
            que.push_back(value);
        }

        int front() {
            return que.front();
        }
    };


    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        MyQueue que;
        for (int i = 0; i < k; ++i) {
            que.push(nums[i]);
        }
        ans.push_back(que.front());
        for (int i = k; i < nums.size(); ++i) {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            ans.push_back(que.front());
        }
        return ans;
    }
};


// 2. 优先队列   构造时加上index信息  方便删除
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> que;
        for (int i = 0; i < k; ++i)
            que.emplace(nums[i], i);
        ans.emplace_back(que.top().first);
        for (int i = k; i < nums.size(); ++i) {
            que.emplace(nums[i], i);
            while (que.top().second < i-k+1)
                que.pop();
            ans.emplace_back(que.top().first);
        }
        return ans;
    }
};




int main() {
    Solution s;
    vector<int> v = {1,3,1,2,0,5};
    auto ans = s.maxSlidingWindow(v, 3);
    for (auto a: ans) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}