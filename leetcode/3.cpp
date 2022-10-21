#include "iostream"
#include "set"
#include "unordered_set"
#include "string"

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> max_substring;
    int max_size = 0;
    for (int i = 0; i != s.size(); ++i){
        while(max_substring.find(s[i]) != max_substring.end())
            max_substring.erase(prev(max_substring.end()));
        max_substring.insert(s[i]);
        if (max_substring.size() > max_size)
            max_size = max_substring.size();
    }
    return max_size;
}



// 滑动窗口 妙用 太妙了
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
        }
        return maxStr;

    }
};

int main() {
    string s = "oidhvyskgqq";
    //cout << lengthOfLongestSubstring(s);
    unordered_set<char> iset;
    for (auto i : s)
        iset.insert(i);

    return 0;
}