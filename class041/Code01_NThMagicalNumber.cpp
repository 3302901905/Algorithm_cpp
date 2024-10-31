#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int mod = 1e9 + 7;

    // 求最大公约数
    // 欧几里得 辗转相除法
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    // 最小公倍数
    int lcm(int a, int b)
    {
        return a * b / gcd(a, b);
    }
    long gcd(long a, long b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    // 最小公倍数
    long lcm(long a, long b)
    {
        return a * b / gcd(a, b);
    }
    
    // 求第n个神奇数
    int nthMagicalNumber(long n, long a, long b)
    {
        long LcmAB = lcm(a, b), res = 0;
        long l = 1, r = n * min(a, b);
        while (l <= r)
        {
            long mid = l + ((r - l) >> 1);
            if (mid / a + mid / b - mid / LcmAB >= n)
            {
                res = mid;
                r = mid - 1;
            }
            else 
            {
                l = mid + 1;
            }
        }
        return (int)(res % mod);
    }

};






















