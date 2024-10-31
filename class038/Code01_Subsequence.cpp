#include<bits/stdc++.h>

using namespace std;

// 字符串的全部子序列
// 子序列可以重复 这道题要求去重
void process1(string& s, int i, string& path, set<string>& res)
{
    if (i == s.size())
    {
        res.insert(path);
    }
    else
    {
        path.push_back(s[i]);
        process1(s, i + 1, path, res);
        path.pop_back();
        process1(s, i + 1, path, res);
    }
}

int main()
{
    string s = "abc";
    string path = "";
    set<string> res;
    process1(s, 0, path, res);
    for (auto& str : res)
    {
        cout << str << endl;
    }
    return 0;
}