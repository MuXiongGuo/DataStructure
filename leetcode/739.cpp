#include "vector"
#include "queue"
#include "stack"
#include "iostream"
#include "unordered_map"
#include "cmath"
#include "string"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 入门版
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size(), 0);
        stk.emplace(0);
        for (int i = 1; i < temperatures.size(); ++i) {
            if (temperatures[i] <= temperatures[stk.top()])
                stk.emplace(i);
            else {
                while (!stk.empty() && temperatures[i] > temperatures[stk.top()]){
                    res[stk.top()] = i - stk.top();
                    stk.pop();
                }
                stk.emplace(i);
            }
        }
        return res;
    }
};

// 简洁版
class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.emplace(i);
        }
        return res;
    }
};