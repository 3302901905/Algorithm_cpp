#include <bits/stdc++.h>

using namespace std;

class solution 
{
public:
    int maxLen = 2 * 1e4 + 1;

    // 严格等于k个不同整数的子数组个数
    // 不超过k 减去 不超过 k-1 的个数即为答案
    int subarraysWithKDifferentIntegers(vector<int>& nums, int k)
    {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
    // 最多k个不同整数的子数组个数
    int atMostKDistinct(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> count(maxLen, 0);
        int res = 0;
        for (int l = 0, r = 0, collect = 0; r < n; ++r)
        {
            // r位置的即将要进来
            if (count[nums[r]]++ == 0)
            {
                ++collect;
            }
            // 如果收集的种类超过了k
            while (collect > k)
            {
                // l开始往右走
                if (--count[nums[l++]] == 0)
                {
                    --collect;
                }
            }
            res = r - l + 1;
        }
        return res;
    }
};