#include<bits/stdc++.h>

using namespace std;

class solution 
{
public:

    int maxCoverage(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end(), [](vector<int>& a, vector<int>& b)
        {
            return a[0] > b[0];
        });

        int max_coverage = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i < n; ++i)
        {
            while (!q.empty() && q.top() <= intervals[i][0])
            {
                q.pop();
            }
            
            q.push(intervals[i][1]);
            
            max_coverage = max(max_coverage, (int)q.size());
            
        }

        return max_coverage;

    }



};















