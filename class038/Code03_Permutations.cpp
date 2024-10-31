#include<bits/stdc++.h>

using namespace std;

void swap(vector<int>& nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void process(vector<int>& nums, int i, vector<vector<int>>& res)
{
    if (i == nums.size())
    {
        vector<int> path;
        for(int& num : nums)
        {
            path.push_back(num);
        }
        res.push_back(path);
    }
    else
    {
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums, i, j);
            process(nums, i + 1, res);
            // 回溯
            swap(nums, i, j);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> res;
    process(nums, 0, res);
    return res;
}

int main()
{

    return 0;
}