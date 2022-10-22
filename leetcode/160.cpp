#include "unordered_set"
#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 直接用ListNode* 就可以 毕竟指针存储的是地址
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = nullptr;
        unordered_set<long long> lookup;
        while (headA != nullptr) {
            lookup.insert((long long) &*headA);
            headA = headA->next;
        }
        while (headB != nullptr) {
            if (lookup.find((long long) &*headB) != lookup.end()){
                p = headB;
                break;
            }
            headB = headB->next;
        }
        return p;
    }
};


// 双指针 空间复杂度由原来的 O(m+n) 降到 O(1) 参考官方解答分析
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};
//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode-solutio-a8jn/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。