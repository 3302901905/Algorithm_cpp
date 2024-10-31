#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // static bool cmp(const vector<int>& a, const vector<int>& b)
    // {
    //     if (a[1] == b[1]) return a[0] < b[0];
    //     return a[1] < b[1];
    // }

    // int scheduleCourse1(vector<vector<int>>& courses) {
    //     sort(courses.begin(), courses.end(), cmp);
    //     int res = 0, times = 0;
    //     for (auto& course : courses)
    //     {
    //         if (times + course[0] <= course[1])
    //         {
    //             times += course[0];
    //             res++;
    //         }
    //     }
    //     return res;
    // }

    int scheduleCourse(vector<vector<int>>& courses)
    {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];
        });

        priority_queue<int, vector<int>> q;

        int times = 0;
        for (auto& course : courses)
        {
            if (times + course[0] <= course[1])
            {
                times += course[0];
                q.push(course[0]);
            }
            else 
            {
                if (!q.empty() && q.top() > course[0])
                {
                    times += course[0] - q.top();
                    q.pop();
                    q.push(course[0]);
                }
            }
        }

        return q.size();
    }

};  










