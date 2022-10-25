#include "string"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int left = 1;
        for (int right = 1; right <= s.size(); ++right) {
            if (right % (2*k) == 0) {
                int mid = (right+left) /2;
                while (mid > left) {
                    swap(s[mid-1], s[left-1]);
                    ++left, --mid;
                }
                left = right+1;
            } else if (right == s.size()) {
                int mid = right > left + k - 1 ? left + k - 1 : right;
                while (mid > left) {
                    swap(s[mid-1], s[left-1]);
                    ++left, --mid;
                }
            }
        }
        return s;
    }
};


// 更好的答案  更简洁
class Solution2 {
public:
    string reverseStr(string s, int k) {
       for (int i = 0; i < s.size(); i+=2*k) {
           if (i + k <= s.size())
               reverse(s.begin()+i, s.begin()+i+k);
           else
               reverse(s.begin()+i, s.end());
       }
        return s;
    }
};




int main() {
    Solution2 s;
    string s1 = "abcdefg";
    int k = 2;
    string res = s.reverseStr(s1, k);
    cout << res;
    return 0;
}