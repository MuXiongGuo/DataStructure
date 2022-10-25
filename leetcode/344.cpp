#include "iostream"
#include "vector"

using namespace std;

// O(1) memory
// swap 可以用位运算 异或实现
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size()-1;
        while (right > left) {
            swap(s[left], s[right]);
            ++left, --right;
        }
    }
};

int main() {
    Solution s;
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    s.reverseString(s1);
    for (auto &a: s1)
        cout << a;
    return 0;
}