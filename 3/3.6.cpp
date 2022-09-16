//
// Created by dell on 2022/9/16.
//
// 解决Josephus问题
#include <iostream>
#include <vector>

using namespace std;
// my solution
void JosephusSolution(int m, int n) {
    if (m == 0){
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
        return;
    }
    vector<int> v1(n + 1);
    auto remain_people = n;
    m += 1;
    int i = 1;
    int count = 1;
    while (remain_people != 0) {
        if (count % m == 0) {
            v1[i] = 1;
            --remain_people;
            cout << i << ' ';
            count = 1;
        } else{
            ++count;
            ++i;
            if (i > n)
                i = 1;
        }
        while (remain_people != 0 && v1[i] != 0){
            ++i;
            if (i > n)
                i = 1;
        }phux
    }
}

// assistant's solution
void Josephus(int n, int m) {
    vector<int> people;
    for (int i = 0; i < n; ++i) {
        people.push_back(i + 1);
    }
    int index = 0;
    while (people.size() > 1) {
        index = (index + m - 1) % people.size();
        cout << people[index] << " ";
        people.erase(people.begin() + index);
    }
    cout << people[0];
}

int main(){
    JosephusSolution(2, 7);
    cout << endl;
    JosephusSolution(6, 4);
    cout << endl;
    JosephusSolution(1, 5);
    cout << endl;
    // 验证另一个solution
    Josephus(2, 7);
    cout << endl;
    Josephus(6, 4);
    cout << endl;
    Josephus(1, 5);
    cout << endl;
    return 0;
}










