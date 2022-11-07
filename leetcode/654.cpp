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


class Solution {
public:

    TreeNode* Partition(vector<int>::iterator left, vector<int>::iterator right, vector<int> &nums) {
        if (left >= right)
            return nullptr;
        auto index = max_element(left, right);
        auto p = new TreeNode(*index);
        p->left = Partition(left, index, nums);
        p->right = Partition(index+1, right, nums);
        return p;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return Partition(nums.begin(), nums.end(), nums);
    }
};

// 单调栈
class Solution2 {
public:

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for (int i = 0; i < nums.size(); ++i) {
            auto p = new TreeNode(nums[i]);
            if (!stk.empty() && stk.back()->val > p->val) {
                stk.back()->right = p;
            } else {
                while (!stk.empty() && stk.back()->val < p->val) {
                    p->left = stk.back();
                    stk.pop_back();
                }
                if (!stk.empty()) {
                    stk.back()->right = p;
                }
            }
            stk.emplace_back(p);
        }
        return stk.front();
    }
};


int main() {
    Solution s;
    vector<int> nums = {3,2,1,6,0,5};
    auto p = s.constructMaximumBinaryTree(nums);
    return 0;
}