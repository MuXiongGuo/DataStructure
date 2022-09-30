#include "iostream"
#include "map"
#include "vector"
using namespace std;

int main() {

    map<int, int> imap;
    imap[43] = 88;
    cout << imap[41] << endl;
    return 0;
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> imap;
        for (int i = 0; i < nums.size(); ++i){
            auto it = imap.find(target-nums[i]);
            if (it == imap.end())
                imap[nums[i]] = i;
            else
                return {it->second, i};
        }
        return {};
    }
};
