#include<bits/stdc++.h>

using namespace std;

class solution 
{
public:

    // 最小覆盖字串
    // 给你一个字符串s 一个字符串t
    // 返回s中包含t所有字符的最小子串
    string minCover(string& s, string& t)
    {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> tMap;
        for (char& c : t)
        {
            tMap[c]--;
        }
        int len = INT_MAX, left = 0, right = 0, start = 0, debt = t.size();
        while (right < s.size())
        {
            if (tMap[s[right]]++ < 0)
            {
                debt--;
            }
            if (debt == 0)
            {
                while (tMap[s[left]] > 0)
                {
                    tMap[s[left]]--;
                    left++;
                }
                if (right - left + 1 < len)
                {
                    len = right - left + 1;
                    start = left;
                }
            }
            right++;
        }

        return len == INT_MAX ? "" : s.substr(start, len);

    }


};