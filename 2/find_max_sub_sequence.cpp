//
// Created by 郭慕雄 on 2022/9/7.
// 第五次

#include <iostream>
#include <vector>

using namespace std;

// 1普通二阶递归
int Solutions1(const vector<int> &a) {
    int i = 0;
    int max_value = 0;
    for (; i != a.size(); ++i) {
        int present_max = 0;
        for (auto j = i; j != a.size(); ++j) {
            present_max += a[j];
            if (present_max > max_value)
                max_value = present_max;
        }
    }
    return max_value;
}


// 2联机算法
int Solutions2(const vector<int> &a) {
    int max_value = 0;
    int present_max = 0;
    for (int i = 0; i != a.size(); ++i) {
        present_max += a[i];
        if (present_max < 0)
            present_max = 0;
        if (present_max > max_value)
            max_value = present_max;
    }
    return max_value;
}

// 3递归算法
// 不能用size_t因为下标最后 会变负号的
int Solutions3(const vector<int> &a, int left, int right) {
    if (left == right) {
        if (a[left] > 0)
            return a[left];
        else
            return 0;
    }
    int mid = (left + right) / 2;
    int left_max_value = Solutions3(a, left, mid);
    int right_max_value = Solutions3(a, mid + 1, right);

    int left_border_sum = 0, max_left_border_sum = 0;
    for (int i = mid; i >= left; --i) {
        left_border_sum += a[i];
        if (left_border_sum > max_left_border_sum)
            max_left_border_sum = left_border_sum;
    }

    int right_border_sum = 0, max_right_border_sum = 0;
    for (int i = mid + 1; i <= right; ++i) {
        right_border_sum += a[i];
        if (right_border_sum > max_right_border_sum)
            max_right_border_sum = right_border_sum;
    }

    if (left_max_value >= right_max_value && left_max_value >= max_left_border_sum + max_right_border_sum)
        return left_max_value;
    if (right_max_value >= left_max_value && right_max_value >= max_left_border_sum + max_right_border_sum)
        return right_max_value;
    if (max_left_border_sum + max_right_border_sum >= right_max_value &&
        max_left_border_sum + max_right_border_sum >= left_max_value)
        return max_left_border_sum + max_right_border_sum;
}


int main() {
    vector<int> a = {-1, 4, -3, 5, -2, -1, -2, 6, -2, 7};
    cout << Solutions1(a) << endl;
    cout << Solutions2(a) << endl;
    cout << Solutions3(a, 0, a.size() - 1);
}

