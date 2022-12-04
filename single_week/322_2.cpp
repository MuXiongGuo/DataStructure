#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        long long res = 0;
        int sum;
        for (int i = 0; i < n/2; ++i) {
            if (i == 0) {
                sum = skill[n-i-1] + skill[i];
            } else {
                if (sum != skill[n-i-1] + skill[i]) {
                    return -1;
                }
            }
            res += skill[i] * skill[n-i-1];
        }
        return res;
    }
};

int main() {


}
