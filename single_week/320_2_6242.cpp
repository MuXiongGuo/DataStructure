#include "vector"
#include "queue"
#include "stack"
#include "iostream"
#include "unordered_map"
#include "cmath"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//
//class Solution {
//public:
//    vector<vector<int>> res;
//    vector<int> tmp;
//    int start_index;
//
//    void Helper(TreeNode *root, vector<int> &queries) {
//        if (root == nullptr || start_index == queries.size())
//            return;
//        Helper(root->left, queries);
//        if (queries[start_index] == root->val) {
//            tmp = {root->val, root->val};
//            res.push_back(tmp);
//            ++start_index;
//            tmp.clear();
//        } else if (queries[start_index] < root->val && tmp.empty()) {
//            tmp.emplace_back(-1);
//            tmp.emplace_back(root->val);
//        } else if (queries[start_index] > root->val && tmp.empty()) {
//            tmp.emplace_back(root->val);
//            tmp.emplace_back(-1);
//        } else if (queries[start_index] < root->val) {
//            tmp[1] = root->val;
//            res.emplace_back(tmp);
//            ++start_index;
//            tmp.clear();
//        } else if (queries[start_index] > root->val) {
//            tmp[0] = root->val;
//        }
//    }
//
//    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
//
//    }
//};

//class Solution {
//public:
//    void MidTravl(TreeNode *root, vector<int> &nums) {
//        if (root == nullptr)
//            return;
//        MidTravl(root->left, nums);
//        nums.emplace_back(root->val);
//        MidTravl(root->right, nums);
//    }
//
//    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
//        vector<vector<int>> res;
//        vector<int> nums;
//        MidTravl(root, nums);
//    }
//};

// 针对二叉树  没用的bst的性质
class Solution1 {
public:
    vector<vector<int>> res;
    vector<int> tem;
    bool flag = false;

    void Search(TreeNode *root, int val) {
        if (root == nullptr || flag)
            return;
        Search(root->left, val);
        if (flag)
            return;
        if (root->val == val) {
            res.push_back({val, val});
            flag = true;
        } else if (root->val < val) {
            if (tem.empty())
                tem = {root->val, -1};
            else
                tem[0] = root->val;
        } else if (root->val > val) {
            if (tem.empty()) {
                res.push_back({-1, root->val});
                flag = true;
            } else {
                tem[1] = root->val;
                res.push_back(tem);
                flag = true;
            }

        }
        Search(root->right, val);
    }

    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
        for (const auto a: queries) {
            flag = false;
            tem.clear();
            Search(root, a);
            if (!flag) {
                res.push_back(tem);
            }
        }
        return res;
    }
};


class Solution2 {
public:
    vector<vector<int>> res;
    vector<int> tem;

    void Search(TreeNode *root, int val, vector<int> &&tem) {
        if (root == nullptr) {
            res.push_back(std::move(tem));
            return;
        }
        if (root->val == val) {
            res.push_back({val, val});
            return;
        } else if (val > root->val) {
            tem[0] = root->val;
            Search(root->right, val, std::move(tem));
        } else if (val < root->val) {
            tem[1] = root->val;
            Search(root->left, val, std::move(tem));
        }

    }

    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
        for (const auto a: queries) {
            Search(root, a, {-1, -1});
        }
        return res;
    }
};

// 转化成有序序列 然后 利用二分查找来做  选择其他方法 都会超时  因为树可能是不平衡的 这点也太重要了
class Solution {
public:
    void GetNums(TreeNode *root, vector<int> &nums) {
        if (root == nullptr)
            return;
        GetNums(root->left, nums);
        nums.emplace_back(root->val);
        GetNums(root->right, nums);
    }

    void BinarySearch(int val, vector<int> &nums, vector<vector<int>> &res) {
        int left = 0, right = nums.size() - 1;
        vector<int> tem{-1, -1};
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == val) {
                res.push_back({val, val});
                return;
            } else if (nums[mid] > val) {
                tem[1] = nums[mid];
                right = mid-1;
            } else {
                tem[0] = nums[mid];
                left = mid+1;
            }
        }
        res.emplace_back(std::move(tem));
    }

    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
        vector<vector<int>> res;
        vector<int> nums;
        GetNums(root, nums);
        for (const auto &a:queries) {
            BinarySearch(a, nums, res);
        }
        return res;
    }
};

int main() {
    //[6,2,13,1,4,9,15,null,null,null,null,null,null,14]
    //[2,5,16]
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(15);
    root->right->right->left = new TreeNode(14);
    vector<int> queries = {2, 5, 16};
    Solution s;
    auto res = s.closestNodes(root, queries);
    for (const auto &a: res) {
        for (const auto &b: a) {
            cout << b << " ";
        }
        cout << endl;
    }
}