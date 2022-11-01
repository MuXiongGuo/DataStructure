#include "stack"
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (res.empty() || res.back() * asteroids[i] > 0)
                res.emplace_back(asteroids[i]);
            else {
                if (res.back() == -asteroids[i])
                    res.pop_back();
                else if (abs(res.back()) < abs(asteroids[i])) {
                    res.pop_back();
                    --i;
                }
            }
        }
        return res;
    }
};