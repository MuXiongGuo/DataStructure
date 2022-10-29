#include "algorithm"
#include "vector"
#include "queue"
#include "unordered_map"
#include "random"

using namespace std;


// 1.自己写的 比较笨笨
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> que;
        sort(nums.begin(), nums.end());
        int current_number = nums[0];
        int current_frequent = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == current_number)
                ++current_frequent;
            else {
                que.emplace(current_frequent, current_number);
                current_frequent = 1;
                current_number = nums[i];
            }
        }
        que.emplace(current_frequent, current_number);
        while (k) {
            ans.emplace_back(que.top().second);
            que.pop();
            --k;
        }
        return ans;
    }
};

// 2. O(k*logn)  利用map统计  然后放到大小为k的堆里, 比直接对map排序快 因为map排序是O(n*logn)  只用维护一个大小为k的堆
class Solution2 {
public:
    class mycomparison {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> ans(k);
        // 小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> que;
        // 统计
        unordered_map<int, int> lookup;
        for (const auto &n: nums)
            ++lookup[n];
        // 放到 最大堆里  且维持k的大小
        for (const auto a: lookup) {
            que.push(a);
            if (que.size() == k + 1)
                que.pop();
        }
        // 取出 所有元素
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = que.top().first;
            que.pop();
        }
        return ans;
    }
};


// 3. 快速排序的 partition 也是可以在平均O(n)的时间内找到第k大的数的, 找到第k大与找到 前k大是一样的, 没必要对vector排序, 可以直接用find
class Solution3 {
public:
    void partition(vector<pair<int, int>> &vec, int start, int end, vector<int> &ans, int k) {
        // 随机数 保证平均时间内 很快    取余技巧 以及 +start 很聪明
        int picked = int(e()) % (end - start + 1) + start;
        swap(vec[picked], vec[end]);
        // start
        int i = start;
        for (int j = start; j <= end - 1; ++j) {
            if (vec[j].second >= vec[end].second) {
                swap(vec[i++], vec[j]);
            }
        }
        swap(vec[i], vec[end]);
        // start ~ i 包含 i 在内  是前 i-start+1个大数
        int k_max = i - start + 1;
        if (k_max > k) {
            partition(vec, start, i, ans, k);
        } else {
            for (int tem = start; tem <= i; ++tem)
                ans.emplace_back(vec[tem].first);
            if (k_max == k)
                return;
            else
                partition(vec, i + 1, end, ans, k - k_max);
        }
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> ans;
        vector<pair<int, int>> vec;
        // 统计
        unordered_map<int, int> lookup;
        for (const auto &n: nums)
            ++lookup[n];
        // 放到vec中 因为map是集合元素  无法进行partition
        for (const auto &a: lookup) {
            vec.emplace_back(a);
        }
        partition(vec, 0, vec.size()-1, ans, k);
        return ans;
    }

private:
    default_random_engine e;
};


int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution3 s;
    auto ans = s.topKFrequent(nums, 2);
    return 0;
}