#include "iostream"
#include "string"
#include "algorithm"
#include "iterator"
#include "vector"
#include "deque"

using namespace std;

// 常量空间秒杀
class Solution {
public:
    string reverseWords(string s) {
        // 去掉首部 尾部的 空格  分两次去   去尾部更高效嘛
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ')
                s.pop_back();
            else
                break;
        }
        reverse(s.begin(), s.end());
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ')
                s.pop_back();
            else
                break;
        }
        // 去除 中间单词 之间的多余空格
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (it != s.begin() && *it == ' ' && *(it - 1) == ' ') {
                it = s.erase(it);
                --it;
            }
        }

        // 以空格为界 反转每个单词
        int left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + left, s.begin() + i);
                left = i + 1;
            } else if (i == s.size() - 1)
                reverse(s.begin() + left, s.end());
        }
        return s;
    }
};

// 官方的常量  速度还很快,  没必要删除那么多次  直接最后再删除  这个思想很重要
class Solution2 {
public:
    string reverseWords(string s) {
        // 反转整个字符串
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0) s[idx++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};
//
//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/reverse-words-in-a-string/solution/fan-zhuan-zi-fu-chuan-li-de-dan-ci-by-leetcode-sol/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



// 双端队列
class Solution3 {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        // 去掉字符串开头的空白字符
        while (left <= right && s[left] == ' ') ++left;

        // 去掉字符串末尾的空白字符
        while (left <= right && s[right] == ' ') --right;

        deque <string> d;
        string word;

        while (left <= right) {
            char c = s[left];
            if (word.size() && c == ' ') {
                // 将单词 push 到队列的头部
                d.push_front(move(word));
                word = "";
            } else if (c != ' ') {
                word += c;
            }
            ++left;
        }
        d.push_front(move(word));

        string ans;
        while (!d.empty()) {
            ans += d.front();
            d.pop_front();
            if (!d.empty()) ans += ' ';
        }
        return ans;
    }
};

//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/reverse-words-in-a-string/solution/fan-zhuan-zi-fu-chuan-li-de-dan-ci-by-leetcode-sol/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 不用双端队列也可以
class Solution4 {
public:
    string reverseWords(string s) {
        vector<string>  words_vec;
        int left = 0, right = s.size()-1;
        while (left <= right) {
            if (s[left] != ' ') {
                string word;
                while (s[left] != ' ' && left <= s.size()-1) word += s[left++];
                words_vec.push_back(std::move(word));
                word = "";
            }
            ++left;
        }
        string ans;
        while (!words_vec.empty()) {
            ans += words_vec.back();
            words_vec.pop_back();
            if (!words_vec.empty()) ans+=' ';
        }
        return ans;
    }
};

class Solution5 {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int index = 0;
        for (int start = 0; start < s.size(); ++start) {
            if (s[start] != ' ') {
                // 分割单词 向前跳一位  第一次不用
                if (index != 0) s[index++] = ' ';

                // 开始 找单词的结束位置, 顺便 把字符串移动过去, 双指针 消除中间多余空格
                int end = start;
                while (end < s.size() && s[end] != ' ') s[index++] = s[end++];

                // 开始反转
                reverse(s.begin()+index-(end-start), s.begin()+index);

                // 跳过去
                start=end;
            }
        }
        s.erase(s.begin()+index, s.end());
        return s;
    }
};

int main() {
    Solution5 s;
    string s1 = "  hello   world!  my friend";
    string res = s.reverseWords(s1);
    cout << res;
    return 0;
}