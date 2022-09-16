//
// Created by dell on 2022/9/16.
//
// 解决Josephus问题
#include <iostream>
#include <vector>

using namespace std;

vector<int> JosephusSolution(int m, int n) {
    vector<int> v1(n + 1);
    m += 1;
    int people_remaining = n;
    int i = 0;
    while (n != 0) {
        if (i % m == 0)
            v1[i] = 1;
        while (v1[i] != 0) ++i;



        }
    return v1;
}












//void Josephus(int n, int m) {
//    vector<int> people;
//    for (int i = 0; i < n; ++i) {
//        people.push_back(i + 1);
//    }
//    int index = 0;
//    while (people.size() > 1) {
//        index = (index + m - 1) % people.size();
//        cout << people[index] << " ";
//        people.erase(people.begin() + index);
//    }
//    cout << people[0];
//}