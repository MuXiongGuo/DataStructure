#include <iostream>
#include "3/Vector.h"
#include <vector>
using namespace std;

int main(){
    //Vector<int> v{12,34,55};
    Vector<int> v;
    int a = 11;
    v.push_back(a);
    v[0] = 99;
    cout << a << v[0];
    return 0;
}

