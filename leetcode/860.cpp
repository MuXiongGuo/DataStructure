#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int money_5 = 0, money_10 = 0;
        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5) {
                money_5 += 1;
            } else if (bills[i] == 10) {
                if (money_5 == 0) {
                    return false;
                } else {
                    --money_5;
                    ++money_10;
                }
            } else {
                if ((money_10 == 0 && money_5 < 3) || (money_10 >= 1 && money_5 == 0)) {
                    return false;
                } else {
                    if (money_10 >= 1) {
                        --money_10;
                        --money_5;
                    } else {
                        money_5 -= 3;
                    }
                }
            }
        }
        return true;
    }
};