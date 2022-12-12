#include "bits/stdc++.h"

using namespace std;

class Allocator {
private:
    vector<int> arr;
public:
    Allocator(int n) : arr(n) {

    }

    int allocate(int size, int mID) {
        int left = 0;
        int res = -1;
        for (int right = 0; right < arr.size(); ++right) {
            if (arr[left] != 0) {
                ++left;
            } else if (arr[right] != 0) {
                left = right+1;
            } else if (right - left + 1 == size) {
                // 记录 修改即可
                res = left;
                for (int i = left; i <= right; ++i) {
                    arr[i] = mID;
                }
                return res;
            }
        }
        return res;
    }

    int free(int mID) {
        int res = 0;
        for (auto &el:arr) {
            if (el == mID) {
                el = 0;
                ++res;
            }
        }
        return res;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */