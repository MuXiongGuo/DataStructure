#include "vector"

using namespace std;

// 错误的做法  因为考虑整体 造成了顾此失彼
// 应该只考虑 局部
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n == 0) {return 0;}
        vector<int> num;
        while (n > 0) {
            num.emplace_back(n%10);
            n /= 10;
        }
        for (int i = num.size()-2; i >= 0; --i) {
            if (num[i] < num[i+1]) {
                // 以 i 为分割线，提取出两个数字
                int tem1=0, tem2=0;
                for (int j = num.size()-1; j > i; --j) {
                    tem1 *= 10;
                    tem1 += num[j];
                }
                tem1 -= 1;
                for (int j = i; j >= 0; --j) {
                    tem1 *= 10;
                    tem2 *= 10;
                    tem2 += 9;
                }
                return tem1 + tem2;
            }
        }
        // 这个数本身就是ok的
        return n;
    }
};

// 贪心
class Solution2 {
public:
    int monotoneIncreasingDigits(int n) {
        if (n == 0) {return 0;}
        vector<int> num;
        while (n > 0) {
            num.emplace_back(n%10);
            n /= 10;
        }
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] > num[i-1]) {
                num[i] -= 1;
                for (int j = i-1; j >= 0; --j) {
                    num[j] = 9;
                }
            }
        }
        int res = 0;
        for (int i = num.size()-1; i >= 0; --i) {
            res *= 10;
            res += num[i];
        }
        return res;
    }
};

// 太聪明了  因为 只要出现一次 就要把之前的都改成9
// 所以只要统计最后一次出现的  再转化即可
// 并且 可以直接用字符串string 做避免了 很多乱七八糟的 vector
class Solution3 {
public:
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i] ) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
