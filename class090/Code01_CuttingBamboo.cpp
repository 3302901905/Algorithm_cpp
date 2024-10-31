#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // 乘法快速幂
    // 10的75次方 ： 10的1001011(二进制)次方

    // 1  0  0  1 0 1 1
    // 64 32 16 8 4 2 1

    // x = 10^1
    // x = x * x;
    // 10^2, 10^4, 10^8, 10^16, 10^32, 10^64...
    // 每次看与其二进制对应的位是否为1，为1则乘上该位对应的10的幂次

    // ans = 1 * 10^1 * 10^2 * 10^8 * 10^64;
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

    int cuttingBamboo(int n)
    {
        if (n == 2) return 1;
        if (n == 3) return 2;

        int tail = n % 3 == 0 ? 1 : (n % 3 == 1 ? 4 : 2);
        int p = tail == 1 ? n : (n - tail) / 3;
        return (int) (power(3, p, mod) * tail % mod);
    }





};

