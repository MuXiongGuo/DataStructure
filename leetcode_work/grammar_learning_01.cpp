#include <cmath>
#include "iostream"
using namespace std;

int main() {
    int ans[1000], count = 0;
    for (int i = 0; i <= 999; i++) {
        int x = 0, y = i;
        while (y != 0) {
            x += pow((y%10),3);
            y /= 10;
        }
        if (x == i) {
            ans[count++] = i;
        }
    }

    while (count > 0) {
        cout << ans[--count] << '\n';
    }
}