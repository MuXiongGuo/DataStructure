#include <xlocale/_stdio.h>
#include <vector>
// #include "test_grammar copy.cpp"
#include "iostream"
using namespace std;

int main() {
    // vector<int> vt = {1,2,3,5};
    vector<vector<int> > vt = {{1, 2, 34, 44}, {55, 66}};
    // 一维数组遍历方式
    int a[] = {2, 3, 4};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        cout << a[i] << endl;
    };
    for (int elm : a) {
        cout << elm << endl;
    }
    // 二维数组遍历方式
    int b [][4] = {{1, 2, 3}, {4, 5, 6}};
    for (const auto &row : b ) {
        for (int elm : row) {
            cout << elm << endl;
        }
    }
    auto &c = b;
    c[0][0] = 100;
    cout << b[0][0] << endl;
    // 字符数组输入
    char str[3] = "";
    scanf("%s", str); // 遇到空格就结束
    // myFunction();
    return 0;
}
