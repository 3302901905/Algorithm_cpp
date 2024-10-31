#include <bits/stdc++.h>

using namespace std;

class solution 
{
public:
    int replaceTheSurStringForBalancedString(string& s)
    {
        int n = s.size();

        // 转化为数组
        // Q W E R -> 0 1 2 3
        // 用count记录
        vector<int> count(n, 0);

        // cnt记录每个字符出现的次数
        vector<int> cnts(4, 0);

        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            count[i] = c == 'W' ? 1 : (c == 'E' ? 2 : (c == 'R' ? 3 : 0));
            cnts[count[i]]++;
        }

        // Q 0 4
        // W 1 12
        // E 2 14
        // R 3 10
        // 40 / 4 = 10
        int debt = 0;
        for (int i = 0; i < 4; ++i)
        {
            if (cnts[i] < n / 4)
            {
                cnts[i] = 0;
            }
            else 
            {
                cnts[i] = n / 4 - cnts[i];
                debt -= cnts[i];
            }
        }

        if (debt == 0)
        {
            return 0;
        }

        int ans = INT_MAX;
        for (int l = 0, r = 0; r < n; ++r)
        {
            if (cnts[s[r]]++ < 0)
            {
                debt--;
            }
            if (debt == 0)
            {
                while (cnts[s[l]] > 0)
                {
                    cnts[s[l++]]--;
                }
                ans = min(ans, r - l + 1);
            }
        }

        return ans;
        
    }
    
};