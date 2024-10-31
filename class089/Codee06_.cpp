#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // 连接棒材的最小花费
    int minCost(vector<int>& sticks)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        int res = 0;
        for (auto& stick : sticks)
        {
            q.push(stick);
        }
        while (!q.empty())
        {
            int cur1 = q.top();
            q.pop();
            int cur2 = q.top();
            q.pop();
            res += cur1 + cur2;
            q.push(cur1 + cur2);
        }
        return res;
    }

};  










