#include "string"
#include "unordered_map"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        for (auto &a : strs) {
            if (ans.empty())
                ans.push_back(vector<string>{std::move(a)});
            else{
                for (auto vec : ans) {
                    unordered_map<char, int> lookup;
                    for (auto word : vec[0])
                        ++lookup[word];
                    for (auto test : a){
                        if (--lookup[test] < 0)

                    }
                }

            }
        }
    }
};
