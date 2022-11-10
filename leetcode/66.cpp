#include "iostream"
#include "vector"
#include "deque"

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        if (digits.back() == 9) {
            carry = 1;
            digits.back() = 0;
        } else {
            digits.back() += 1;
        }
        for (int i = digits.size()-2; i >= 0; --i) {
            if (carry == 0)
                break;
            else if (digits[i] == 9)
                digits[i] = 0;
            else if (digits[i] != 9) {
                digits[i] += 1;
                carry = 0;
            }
        }
        if (carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};


