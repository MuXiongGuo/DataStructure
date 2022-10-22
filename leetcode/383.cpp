#include "unordered_map"
#include "string"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> lookup;
        for (const auto &a : magazine)
            ++lookup[a];
        for (const auto &a : ransomNote) {
            --lookup[a];
            if (lookup[a] < 0)
                return false;
        }
        return true;
    }
};