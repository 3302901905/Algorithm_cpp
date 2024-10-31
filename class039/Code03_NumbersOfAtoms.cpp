#include<bits/stdc++.h>

using namespace std;

int where = 0;

map<string, int> process(string& s, int i)
{
    map<string, int> res;
    string name;
    map<string, int> pre = NULL;
    int cnt = 0;
    while (i < s.size() && s[i] != ')')
    {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] == '(')
        {
            fill(name, pre, cnt ,res);
            name = "";
            pre = NULL;
            cnt = 0;
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                name.push_back(s[i++]);
            }
            else 
            {
                pre = process(s, i + 1);
                i = where + 1;
            }
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            name += s[i++];
        }
        else 
        {
            cnt = cnt * 10 + (s[i++] = '0');
        }
    }
    fill(name, pre, cnt, res);
    where = i;
    return res;
}

void fill(string& name, map<string, int>& pre, int& cnt, map<string, int>& res)
{
    if (name.size() != 0 || pre != NULL)
    {
        cnt = cnt == 0 ? 1 : cnt;
        if (name.size() != 0)
        {
            res.push_back(name, res.count(name) + cnt);
        }
        else 
        {
            for (auto& p : pre)
            {
                res.push_back(p.first, res.count(name) + p.second * cnt);
            }
        }
    }
}



