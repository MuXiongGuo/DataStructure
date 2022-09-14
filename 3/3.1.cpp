//
// Created by 郭慕雄 on 2022/9/14.
//
#include "vector"
#include "iostream"

using namespace std;
// 答案
//void PrintLots(vector<int> &L, vector<int> &P) {
//    int i = 0;
//    int j = 0;
//    while (i < L.size() && j < P.size()) {
//        if (P[j] == i) {
//            cout << L[i] << " ";
//            ++j;
//        }
//        ++i;
//    }
//}
// 我的
void PrintLots(vector<int> &L, vector<int> &P) {
    for(auto &p:P){
        if(p<=L.size())
            cout << L[p-1] << " ";
    }
}

int main(){
    vector<int> L = {1,2,3,4,5,6,7,8,9,10};
    vector<int> P = {1,3,5,7,9,21};
    PrintLots(L,P);
    return 0;
}