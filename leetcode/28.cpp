#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
            return -1;
        int left;
        for (int i = 0; i < haystack.size(); ++i) {
           if (haystack[i] == needle[0]) {
               int index = 0;
               left = i;
               int tem = i;
               while (tem < haystack.size() && index < needle.size() && haystack[tem] == needle[index]) ++tem, ++index;
               if (index == needle.size())
                   return left;
           }
        }
        return -1;
    }
};


int main() {
    Solution s;
    cout << s.strStr("mississippi", "issip") << endl;
    return 0;
}