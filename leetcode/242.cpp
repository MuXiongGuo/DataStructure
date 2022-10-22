#include "map"
#include "string"

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> lookup;
        for (const auto &a : s)
            --lookup[a];
        for (const auto &a : t)
            ++lookup[a];
        for (const auto &a : lookup)
            if (a.second != 0)
                return false;
        return true;
    }
};