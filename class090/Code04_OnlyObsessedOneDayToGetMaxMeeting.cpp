#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // 最多能参加的会议数
    // 给出每个会议的开始时间和结束时间
    // 但只需要参加一天
    // 返回最多能参加的会议数
    int maxMeeting(vector<vector<int>> &meetings)
    {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0];
        });

        int minDay = meetings[0][0], maxDay = meetings[0][1];
        for (auto &meeting : meetings)
        {
            maxDay = max(maxDay, meeting[1]);
        }

        priority_queue<int, vector<int>, greater<int>> heap;
        int curDay, i = 0, res = 0;
        for (curDay = minDay; curDay <= maxDay; ++curDay)
        {
            while (i < n && meetings[i][0] == curDay)
            {
                heap.push(meetings[i++][1]);
            }

            while (!heap.empty() && heap.top() < curDay)
            {
                heap.pop();
            }

            if (!heap.empty())
            {
                heap.pop();
                res++;
            }
            
        }

        return res;
    }

    // 全排列暴力解
    int maxMeeting2(vector<vector<int>> &meetings)
    {
        return process(meetings, 0, meetings.size());
    }
    
    int process(vector<vector<int>> &meetings, int index, int n)
    {
        int ans = 0;
        if (index == n)
        {
            for (int j = 0, cur = -1; j < n; ++j)
            {
                if (cur <= meetings[j][0])
                {
                    ans++;
                    cur = meetings[j][1];
                }
            }
        }
        else 
        {
            for (int i = index; i < n; ++i)
            {
                swap(meetings, index, i);
                ans = max(ans, process(meetings, index + 1, n));
                swap(meetings, index, i);
            }
        }
        return ans;
    }

    void swap(vector<vector<int>> &meetings, int i, int j)
    {
        vector<int> tmp = meetings[i];
        meetings[i] = meetings[j];
        meetings[j] = tmp;
    }

    // 随机生成数组
    // 每个数字从1 ~ n
    vector<vector<int>> getRandomArray(int n, int size)
    {
        vector<vector<int>> ans(size, vector<int>(2, 0));
        srand(time(0));
        for (int i = 0; i < size; ++i) 
        {
            ans[i][0] = rand() % n + 1;
            ans[i][1] = rand() % n + 1;
        }

        return ans;
    }

};

int main()
{
    
    return 0;
}




















