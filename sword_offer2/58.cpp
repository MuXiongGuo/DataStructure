#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin()+n);
        reverse(s.begin()+n, s.end());
        reverse(s.begin(), s.end());
        vector<int> v; // 
        return s;
    }
};