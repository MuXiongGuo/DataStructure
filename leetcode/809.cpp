#include "bits/stdc++.h"

using namespace std;

// 统计 观察规律
class Solution {
public:
    void GetLookUp(string const &word, vector<pair<char, int>> &lookup) {
        int count = 0;
        for (int i = 0; i < word.size(); ++i) {
            ++count;
            if (i == word.size() - 1 || word[i] != word[i + 1]) {
                lookup.emplace_back(pair<char, int>{word[i], count});
                count = 0;
            }
        }
    }

    bool IsValid(vector<pair<char, int>> &lookup1, vector<pair<char, int>> &lookup2) {
        if (lookup1.size() != lookup2.size())
            return false;
        for (int i = 0; i < lookup1.size(); ++i) {
            if (lookup1[i].first != lookup2[i].first || lookup1[i].second < lookup2[i].second ||
                (lookup1[i].second != lookup2[i].second && lookup1[i].second == 2))
                return false;
        }
        return true;
    }

    int expressiveWords(string s, vector<string> &words) {
        vector<pair<char, int>> lookup;
        GetLookUp(s, lookup);
        int res = 0;
        for (const auto &word: words) {
            decltype(lookup) lookup_word;
            GetLookUp(word, lookup_word);
            if (IsValid(lookup, lookup_word)) {
                ++res;
            }
        }
        return res;
    }
};

// 其实没那么麻烦  直接 双指针 一根在 s上 另一根在word上 KO
// 通过最后  是否都到头 可以判断出 是否有冗余元素  太牛了
class Solution2 {
public:
    bool IsValid(string const &s1, string const &s2) {
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            char ch1 = s1[i], ch2 = s2[j];
            if (ch1 != ch2)
                return false;
            int cnt1 = 0, cnt2 = 0;
            while (i < s1.size() && s1[i] == ch1) {
                ++cnt1, ++i;
            }
            while (j < s2.size() && s2[i] == ch2) {
                ++cnt2, ++j;
            }
            if (cnt2 > cnt1 || (cnt1 != cnt2 && cnt1 == 2))
                return false;
        }
        return i == s1.size() && j == s2.size();
    }

    int expressiveWords(string s, vector<string> &words) {
        int ans = 0;
        for (const string& word: words) {
            if (IsValid(s, word)) {
                ++ans;
            }
        }
        return ans;
    }
};
