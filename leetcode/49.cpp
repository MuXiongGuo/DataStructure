#include "bits/stdc++.h"

using namespace std;

// 超时了
class Solution6 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        for (auto &a : strs) {
            if (ans.empty())
                ans.push_back(vector<string>{std::move(a)});
            else{
                bool flag = true;
                for (auto &vec : ans) {
                    if (vec[0].size() != a.size())
                        continue;
                    unordered_map<char, int> lookup;
                    for (auto word : vec[0])
                        ++lookup[word];
                    for (auto test : a) {
                        if (--lookup[test] < 0)
                            goto here;
                    }
                    vec.push_back(std::move(a));
                    flag = false;
                    break;
                    here:
                    continue;
                }
                if (flag)
                    ans.push_back(vector<string>{std::move(a)});
            }
        }
        return ans;
    }
};
int aa() {
    return 1;
}

class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        // fn这个要捕获的局部变量 直接定义在了里面, 其实根本不用捕获  又不是局部变量，可以直接使用的！！！
        // [&](size_t acc, int num) 这是accumulate里的一个 lambda，两个lambda套在里面而已
        // 自动使用引用捕获 捕获外面的 捕获的是 fn
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num); // << 1可以使得 每个位置的权重不同  无符号不怕上溢出 自动取模的余
            });
        };
        // decltype(arrayHash) 不加*  因为lambda 推出的类型是 函数指针
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

class Solution3 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    }
};

// 哈希函数 不用特地取余 底层会自动取余数
// 一个桶里放多个 不是那种 自动扩开的 扩开的一般是 一个桶里只一个
// 但是 长度居然不是 素数吗？？？ 正在 使用的 桶子
int main()
{
    auto myhash = [](const int &el)->size_t {return el;};
    unordered_set<int, decltype(myhash)> sampleSet(0, myhash);

    // Inserting elements
    sampleSet.insert(5);
    sampleSet.insert(10);
    sampleSet.insert(15);
    sampleSet.insert(20);
    sampleSet.insert(24);

    sampleSet.insert(32);
    sampleSet.insert(330);
    sampleSet.insert(135);
    sampleSet.insert(244);
    sampleSet.insert(2231);

    sampleSet.insert(322);
    sampleSet.insert(3330);
    sampleSet.insert(1335);
    sampleSet.insert(2444);
    sampleSet.insert(22331);
    cout << "The sampleSet container has " << sampleSet.bucket_count()
         << " number of buckets\n\n";

    for (auto itr = sampleSet.begin(); itr != sampleSet.end(); itr++) {
        cout << "The Element " << (*itr) << " is present in the bucket: "
             << sampleSet.bucket(*itr);
        cout << endl;
    }

    cout << sampleSet.bucket_size(0);
    return 0;
}
//int main() {
////    Solution s;
////    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
////    auto res = s.groupAnagrams(strs);
//    auto myhash = [](const int &el)->size_t {return el;};
//    unordered_set<int, decltype(myhash)> s(0,myhash);
//    s.insert(3123), s.insert(49184371);
//    cout << s.bucket_count() << endl;
//    cout << s.max_bucket_count() << endl;
//    cout << s.bucket(3123) << endl;
//    cout << s.max_load_factor() <<endl;
//
//    unordered_map<string, int> m;
//    cout << m.bucket_count();
//    return 0;
//}

// 其实 策略也不太重要
// 只要定义了 一个哈希转化的函数就行  重要的是 区别每一位  以及每一个的重复
// << 1 必须有  但 转化成素数 只是锦上添花
class Solution4 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u);
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};


class Solution5 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        // fn这个要捕获的局部变量 直接定义在了里面, 其实根本不用捕获  又不是局部变量，可以直接使用的！！！
        // [&](size_t acc, int num) 这是accumulate里的一个 lambda，两个lambda套在里面而已
        // 自动使用引用捕获 捕获外面的 捕获的是 fn
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) + (num); // << 1可以使得 每个位置的权重不同  无符号不怕上溢出 自动取模的余
            });
        };
        // decltype(arrayHash) 不加*  因为lambda 推出的类型是 函数指针
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
