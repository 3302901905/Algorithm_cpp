#include<bits/stdc++.h>

using namespace std;

void process1(vector<int>& nums, int i, vector<int>& path, int size, vector<vector<int>>& res)
{
    if (i == nums.size())
    {
        vector<int> curPath;
        for (int j = 0; j < size; ++j)
        {
            curPath.push_back(path[j]);
        }
        res.push_back(curPath);
    }
    else
    {
        int j = i + 1;
        while (j < nums.size() && nums[i] == nums[j])
        {
            j++;
        }

        // 当前数要0个
        process1(nums, j, path, size, res);

        for (; i < j; ++i)
        {
            path[size++] = nums[i];
            process1(nums, j, path, size, res);  
        }
        
    }
}

void solve(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
}

int main()
{
    return 0;
}