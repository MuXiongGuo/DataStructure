#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "map"

using namespace std;

// 难点是 容器选择  另一种是 unordered_map<出发机场, multiset<到达机场>> targets 但是不能快速删除
// 而map的可以用 懒惰删除
class Solution {
public:
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;

    // 用bool因为只要找一个就够了 先被找到的一定是字典序的
    // 每次只要读取res的末尾即可 不需要传递额外参数
    bool BackTracking(vector<string> &res, int nums) {
        if (res.size() == nums+1) {
            return true;
        }
        for(auto &target:targets[res.back()]) {
            if (target.second !=0 ) {
                --target.second;
                res.emplace_back(target.first);
                if (BackTracking(res, nums)) {return true;}
                ++target.second;
                res.pop_back();
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets) {
        vector<string> res;
        for (const auto &ticket: tickets) {
            ++targets[ticket[0]][ticket[1]];
        }
        res.emplace_back("JFK");
        BackTracking(res, int(tickets.size()));
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<string>> tickets = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
    auto res = s.findItinerary(tickets);
    for (const auto &str:res) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}

//int main() {
//    unordered_map<string, map<string, int>>res;
//    res["abc"]["dd"] = 18;
//    // 不存在的key会导致被添加进去
//    for (auto &a:res["cc"]) {
//        cout << "hello";
//    }
//    // 但是这个key对应一个空的map, 相当于去遍历空集合 并不会意外访问!
//    for (auto &a:res["cc"]) {
//        cout << (a.second != 0);
//    }
//    unordered_map<string, int>lookup;
//    lookup["dd"];
//    return 0;
//}