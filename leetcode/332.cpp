#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> lookup;

    void CreatLookUp(const vector<vector<string>> &tickets) {
        for (const auto &a:tickets) {
            lookup[a[0]].push_back(a[1]);
        }
    }

    string FindTickets(vector<string> &tem) {
        int res = 0;
        for (int i = 1; i < tem.size(); ++i) {
            if (tem[res] > tem[i])
                res = i;
        }
        string str = tem[res];
        tem.erase(tem.begin()+res);
        return str;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets) {
        CreatLookUp(tickets);
        vector<string> res;
        string start = "JFK";
        res.emplace_back(start);
        int count = tickets.size();
        while (count) {
            --count;
            auto &tem = lookup[start];
            start = FindTickets(tem);
            res.emplace_back(start);
        }
        return res;
    }
};

int main() {
    // [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    vector<vector<string>> tickets = {{"JFK", "SFO"},
                                      {"JFK", "ATL"},
                                      {"SFO", "ATL"},
                                      {"ATL", "JFK"},
                                      {"ATL", "SFO"}};
    Solution s;
    auto res = s.findItinerary(tickets);
    for (const auto &a:res) {
        cout << a << " ";
    }
    return 0;
}