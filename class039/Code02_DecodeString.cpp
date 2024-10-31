#include<bits/stdc++.h>

using namespace std;

int where = 0;

// 含有嵌套的字符串解码
string getDecodeString(string& str, int i)
{
    string path = "";
    int n = str.size(), cnt = 0;
    while (i < n && str[i]!= ']')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            cnt = cnt * 10 + (str[i++] - '0');
        }
        else if (str[i] != '[')
        {
            path += str[i++];
        }
        else
        {
            while (cnt > 0)
            {
                path += getDecodeString(str, i + 1);
                cnt--;
            }
            i = where + 1;  
        }
    }
    where = i;
    return path;
}

