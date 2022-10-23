#include "string"
#include "unordered_map"
#include "vector"

using namespace std;

// 超时了
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        for (auto &a : strs) {
            if (ans.empty())
                ans.push_back(vector<string>{std::move(a)});
            else{
                bool flag = true;
                for (auto &vec : ans) {
                    if (vec[0].size() != a.size())
                        continue;
                    unordered_map<char, int> lookup;
                    for (auto word : vec[0])
                        ++lookup[word];
                    for (auto test : a) {
                        if (--lookup[test] < 0)
                            goto here;
                    }
                    vec.push_back(std::move(a));
                    flag = false;
                    break;
                    here:
                    continue;
                }
                if (flag)
                    ans.push_back(vector<string>{std::move(a)});
            }
        }
        return ans;
    }
};


class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = s.groupAnagrams(strs);
    return 0;
}