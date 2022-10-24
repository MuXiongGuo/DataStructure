#include "unordered_set"

using namespace std;

// 我的解法 哈希表
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> appeared;
        while (n != 1) {
            if (appeared.count(n))
                return false;
            appeared.insert(n);
            int tem = n;
            n = 0;
            while (tem != 0) {
                n += (tem % 10) * (tem % 10);
                tem /= 10;
            }
        }
        return true;
    }
};

// 要考虑问题的最大范围, 以及转换问题格式, 本质上是链表有没有还 所以还可以用快慢指针
// 时间复杂度分析, 每次都要求 logn 每一位故为 logn 之后是 loglogn 以此类推  243为界限, 一旦低于243就回不去了 故243用来表示低于等于3位的

// 2. 使用快慢指针解决问题
class Solution2 {
public:
    int getNext(int n) {
        int total = 0;
        while (n != 0) {
            total += (n % 10) * (n % 10);
            n /= 10;
        }
        return total;
    }

    bool isHappy(int n) {
        int slow = n, fast = getNext(n);
        while (slow != fast && fast != 1) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};


int main() {
    Solution2 s;
    s.isHappy(19);
    return 0;
}