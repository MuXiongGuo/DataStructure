#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) {return 1;}
        int total_candy = ratings[0] > ratings[1] ? 2:1, prev = total_candy;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                total_candy += prev+1;
                prev += 1;
            } else {
                total_candy += 1;
                prev = 1;
            }
        }
        return total_candy;
    }
};

// 想做出来很难的思路  从头到尾然后考虑左孩子 再从尾部到头部（能利用前一次的比较结果） 考虑右孩子，糖果数为当前最大或者是+1
// 一起考虑一定会顾此失彼
class Solution2 {
public:
    int candy(vector<int>& ratings) {
        vector<int> candys(ratings.size(), 0);
        // 左到右
        for(int i = 0; i < ratings.size(); ++i) {
            if (i == 0 || ratings[i] <= ratings[i-1]) {
                candys[i] = 1;
            } else {
                candys[i] = candys[i-1] + 1;
            }
        }
        // 右到左
        for(int i = ratings.size()-2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candys[i] = max(candys[i], candys[i + 1] + 1);
            }
        }
        int sum = 0;
        for (const auto a:candys) {
            sum += a;
        }
        return sum;
    }
};

// 官方解法  去官网看吧 很巧妙 只用了常数空间完成
class Solution3 {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ret = 1;
        int inc = 1, dec = 0, pre = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                inc = pre;
            } else {
                dec++;
                if (dec == inc) {
                    dec++;
                }
                ret += dec;
                pre = 1;
            }
        }
        return ret;
    }
};

//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/candy/solution/fen-fa-tang-guo-by-leetcode-solution-f01p/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。