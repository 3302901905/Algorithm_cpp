#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // 一个数分成k份最大乘积
    int maxProduct(int n, int k)
    {
        int mod = 1000000007;
        long avg = n / k;
        int rest = n % k;
        long part1 = power(avg, k - rest, mod);
        long part2 = power(avg + 1, rest, mod);
        return (int) (part1 * part2 % mod);
    }

    int mod = 1000000007;
    long power(long x, int n, int mod)
    {
        long ans = 1;
        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                ans = (ans * x) % mod;
            }
            x = (x * x) % mod;
            n >>= 1;
        }
        return ans;
    }

};

