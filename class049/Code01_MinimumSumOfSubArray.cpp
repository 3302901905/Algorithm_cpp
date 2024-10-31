#include<bits/stdc++.h>

using namespace std;

class solution 
{
public:

    // 累加和大于target的最短子数组长度
    int minLength(vector<int>& nums, int target)
    {
        int left = 0, right = 0, n = nums.size(), sum = 0, ans = INT_MAX;
        while (right < n)
        {
            sum += nums[right++];
            while (sum >= target)
            {
                sum -= nums[left++];
                ans = min(ans, (right - left + 1));
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }



};