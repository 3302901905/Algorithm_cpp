#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // 我最多能参加的会议数
    int maxMeeting(vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        });

        int res = 0;
        int end = 0;
        for (auto &meeting : meetings)
        {
            if (meeting[0] >= end)
            {
                res++;
                end = meeting[1];
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
    Solution s;
    int times = 1;
    int maxN = 100;
    int maxSize = 10;
    vector<vector<int>> arr;
    for (int i = 0; i < times; ++i)
    {
        arr = s.getRandomArray(maxN, maxSize);
        int ans1 = s.maxMeeting(arr);
        int ans2 = s.maxMeeting2(arr);
        if (ans1 != ans2)
        {
            cout << "Oops!" << endl;
        }
        else 
        {
            cout << "yes!" << endl;
        }
    }
    return 0;
}




















