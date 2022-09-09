//
// Created by 郭慕雄 on 2022/7/5.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hoare_partition(vector<int> &A, int p, int r);

int hoare_partition(vector<int> &A, int p, int r) {
    int x = A[p];
    int i = p - 1;
    int j = r + 1;
    while (true) {
        do {
            --j;
        } while (A[j] > x);

        do {
            ++i;
        } while (A[i] < x);
        if (i < j)
            swap(A[i], A[j]);
        else
            return j;
    }

}

int main() {
    vector<int> A = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
    int j = hoare_partition(A, 0, A.size() - 1);
    return 0;
}