#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        char first = coordinates[0], second = coordinates[1];
        if (first%2 == second%2) {
            return false;
        }
        return true;
    }
};