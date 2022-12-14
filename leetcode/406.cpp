#include "bits/stdc++.h"

using namespace std;

// O(n^2)
class Solution {
public:
    // 身高小的在前面 相同则看位次
    static bool compare(vector<int> &a, vector<int> &b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        } else {
            return a[1] < b[1];
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> res(people.size());
        for (int i = 0; i < people.size(); ++i) {
            int k = people[i][1], index = 0;
            while (k >= 0) {
                if (res[index].empty() || res[index][0] == people[i][0]) {
                    --k;
                }
                ++index;
            }
            res[index-1] = std::move(people[i]);
        }
        return res;
    }
};

// 代码随想录
// 相当聪明
// 先排高的, 相同高的 按照index 的逆向排序 保证了每次插入时都能是最佳位置
// 版本一
class Solution2 {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort (people.begin(), people.end(), cmp);
        vector<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1];
            que.insert(que.begin() + position, people[i]);
        }
        return que;
    }
};

// 版本二
// 使用链表 虽然也是n^2  但是它插入速度要快很多了
class Solution3 {
public:
    // 身高从大到小排（身高相同k小的站前面）
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort (people.begin(), people.end(), cmp);
        list<vector<int>> que; // list底层是链表实现，插入效率比vector高的多
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1]; // 插入到下标为position的位置
            std::list<vector<int>>::iterator it = que.begin();
            while (position--) { // 寻找在插入位置
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end()); // 链表转vec 线性时间内转完
    }
};

int main() {
    Solution solution;
    vector<vector<int>> people = {{7, 0},
                                  {4, 4},
                                  {7, 1},
                                  {5, 0},
                                  {6, 1},
                                  {5, 2}};
    auto res = solution.reconstructQueue(people);
    for (const auto &a: res) {
        cout << a[0] << " " << a[1] << endl;
    }
    return 0;
}