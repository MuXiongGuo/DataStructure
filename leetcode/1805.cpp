#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> lookup;
        int start = 0;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] <= 57 && word[i] >= 48) {
                start = i;
                while (word[i] <= 57 && word[i] >= 48 && i < word.size()) {
                    ++i;
                }
                while (start+1 < word.size() && (word[start+1] <= 57 && word[start+1] >= 48) && word[start] == '0') {
                    ++start;
                }
                lookup.insert(word.substr(start, i-start));
            }
        }
        return lookup.size();
    }
};