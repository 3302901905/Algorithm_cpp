#include <bits/stdc++.h>

using namespace std;

class  Solution
{
public:
    // pair -> 会议室需要被占用的时间间隔 从 pair.first 到 pair.second
    // 返回需要的最少的会议室
    int minMeetingRooms(vector<pair<int, int>>& meetings)
    {
        int res = 0, heapSize = 0;

        sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int,int>& b)
        {
            return a.first < b.first;
        });

        priority_queue<int, vector<int>, greater<int>> q;
        q.push(meetings[0].second);

        for (auto& meeting : meetings)
        {
            while (!q.empty() && q.top() <= meeting.first)
            {
                q.pop();
            }
            q.push(meeting.second);
            heapSize++;
            res = max(res, heapSize);
        }
        
        return res;

    }

};

