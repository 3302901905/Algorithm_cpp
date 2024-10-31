#include<bits/stdc++.h>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
}ListNode;

// struct Compare {
//     bool operator()(int left, int right) {
//         return left > right; // 注意这里返回 left > right 来实现最小堆
//     }
// };
struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

// 合并k个有序链表
class solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        // priority_queue<int, vector<int>, greater<int>> queue;
        
        for (ListNode* node : lists)
        {
            if (node != nullptr)
            {
                q.push(node);
            }
        }

        if (q.empty())
        {
            return nullptr;
        }

        ListNode* dummy = q.top();
        q.pop();
        ListNode* pre = dummy;
        if (pre->next != nullptr)
        {
            q.push(pre->next);
        }
        while (!q.empty())
        {
            ListNode* cur = q.top();
            q.pop();
            pre->next = cur;
            pre = cur;
            if (cur->next != nullptr)
            {
                q.push(cur->next);
            }
        }

        return dummy;

    }


};

int main()
{
    return 0;
}

