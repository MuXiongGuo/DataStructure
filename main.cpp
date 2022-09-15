#include <iostream>
#include "3/Vector.h"
#include "3/List.h"
#include <vector>
using namespace std;


int &f(const int &a){
    int b = 99;
    return b;
}

int main(){
    //Vector<int> v{12,34,55};
//    Vector<int> v(10);
//    for(int i = 0; i<10;++i)
//        v[i] = i;
//
//    Vector<int>v2;
//    v2 = v;
//    v[0]
//    int a = 11;
//    v.push_back(a);
//    v[0] = 99;
//    cout << a << v[0];
//    auto &zz = f(a);
//
//    cout <<zz;
//    int b = int(); // 命为int的临时变量
//    auto c = vector<int>();

//    List<int> v3;
//    for(int i = 0; i<10;++i)
//        v3.push_back(i);

//    List<int>v4;
//    v4 = v3;
//    vector<int>a;
//    cout << a.size();
    vector<int> v;
    vector<int> v2(111);
    List<vector<int>> v5 = {vector<int>(18)};
    v5.push_back(vector<int>(13));
    v5.push_back(std::move(v2));

    // 或者说 本质问题是 对一个引用类型 再取std::move的时候，会不会出现问题
    return 0;
}

