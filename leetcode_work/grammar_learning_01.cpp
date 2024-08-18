#include <cmath>
#include <cstdio>

#include "iostream"
using namespace std;

int main() {
    // int ans[1000], count = 0;
    // for (int i = 0; i <= 999; i++) {
    //     int x = 0, y = i;
    //     while (y != 0) {
    //         x += pow((y%10),3);
    //         y /= 10;
    //     }
    //     if (x == i) {
    //         ans[count++] = i;
    //     }
    // }

    // while (count > 0) {
    //     cout << ans[--count] << '\n';
    // }

    // 浮点数上溢出
    float tooBig = 3.4e38f * 3003.0f;
    printf("%e\n", tooBig);

    float a, b;
    a = 2.0e15 + 1.0;
    b = a - 2.0e15;
    auto c = '\a';
    // printf("%e", a);
    auto aa = 66.2 - 'A';
    cout << sizeof(double) << endl;

    // 输出蜂鸣音
    printf("\a");

}