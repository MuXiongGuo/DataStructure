#include <iostream>
#include "3/Vector.h"
#include <vector>
using namespace std;


int &f(const int &a){
    int b = 99;
    return b;
}

int main(){
    //Vector<int> v{12,34,55};
    const Vector<int> v(10);
    auto a = v[0];
//    v[0]
//    int a = 11;
//    v.push_back(a);
//    v[0] = 99;
//    cout << a << v[0];
//    auto &zz = f(a);
//
//    cout <<zz;
    int b = int(); // 命为int的临时变量
    auto c = vector<int>();
    return 0;
}

