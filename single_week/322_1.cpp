#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream ins(sentence);
        string word;
        char first, last;
        int count = 0;
        while (ins >> word) {
            if (count == 0) {
                first = word[0];
                last = word.back();
            } else {
                if (word[0] != last) {
                    return false;
                }
                last = word.back();
            }
            ++count;
        }
        return last == first;
    }
};

int main() {

    Solution s;
    cout << s.isCircularSentence("Leetcode is coo") << endl;

}

