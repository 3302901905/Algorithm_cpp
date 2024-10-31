#include<bits/stdc++.h>

using namespace std;

map<int, int> dp;

int minDays(int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp.count(n))
    {
        return dp[n];
    }
    int ans = min(n % 2 + 1 + minDays(n / 2), n % 3 + 1 + minDays(n / 3));
    dp[n] = ans;
    return ans;
}








