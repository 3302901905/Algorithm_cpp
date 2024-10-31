#include <bits/stdc++.h>

using namespace std;

struct cmp1 {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

struct cmp2 {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.first < b.first;
    }
};

class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {   
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); ++i)
        {
            projects.push_back({profits[i], capital[i]});
        }
        // 启动资金的小根堆 被锁住的项目
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> minCapital;
        // 利润的大根堆 可以做的已解锁的项目
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> maxProfit;

        int n = profits.size();

        for (int i = 0; i < n; ++i)
        {
            minCapital.push(projects[i]);
        }   

        while (k > 0)
        {
            while (!minCapital.empty() && minCapital.top().second <= w)
            {
                maxProfit.push(minCapital.top());
                minCapital.pop();
            }

            if (!maxProfit.empty())
            {
                w += maxProfit.top().first;
                maxProfit.pop();
            }
            else
            {
                break;
            }

            --k;
        }

        return w;

    }
    

};

int main()
{
    Solution solution;

    // 测试用例 1
    int k1 = 2; // 可以进行的项目数量
    int w1 = 0; // 初始资金
    vector<int> profits1 = {1, 2, 3}; // 项目的利润
    vector<int> capital1 = {0, 1, 1}; // 项目的启动资金

    int result1 = solution.findMaximizedCapital(k1, w1, profits1, capital1);
    cout  << result1 << endl; // 输出结果

    // 测试用例 2
    int k2 = 3; // 可以进行的项目数量
    int w2 = 1; // 初始资金
    vector<int> profits2 = {2, 3, 5}; // 项目的利润
    vector<int> capital2 = {0, 1, 2}; // 项目的启动资金

    int result2 = solution.findMaximizedCapital(k2, w2, profits2, capital2);
    cout  << result2 << endl; // 输出结果

    // 测试用例 3
    int k3 = 1; // 可以进行的项目数量
    int w3 = 5; // 初始资金
    vector<int> profits3 = {10, 20, 30}; // 项目的利润
    vector<int> capital3 = {5, 10, 15}; // 项目的启动资金

    int result3 = solution.findMaximizedCapital(k3, w3, profits3, capital3);
    cout  << result3 << endl; // 输出结果

    // 测试用例 4
    int k4 = 4; // 可以进行的项目数量
    int w4 = 0; // 初始资金
    vector<int> profits4 = {5, 10, 15, 20}; // 项目的利润
    vector<int> capital4 = {0, 1, 2, 3}; // 项目的启动资金

    int result4 = solution.findMaximizedCapital(k4, w4, profits4, capital4);
    cout  << result4 << endl; // 输出结果

    // 测试用例 5
    int k5 = 5; // 可以进行的项目数量
    int w5 = 3; // 初始资金
    vector<int> profits5 = {1, 2, 3, 4, 5}; // 项目的利润
    vector<int> capital5 = {1, 2, 3, 4, 5}; // 项目的启动资金

    int result5 = solution.findMaximizedCapital(k5, w5, profits5, capital5);
    cout  << result5 << endl; // 输出结果

    // 测试用例 6
    int k6 = 2; // 可以进行的项目数量
    int w6 = 10; // 初始资金
    vector<int> profits6 = {5, 15, 25}; // 项目的利润
    vector<int> capital6 = {5, 10, 20}; // 项目的启动资金

    int result6 = solution.findMaximizedCapital(k6, w6, profits6, capital6);
    cout  << result6 << endl; // 输出结果

    // 测试用例 7
    int k7 = 3; // 可以进行的项目数量
    int w7 = 0; // 初始资金
    vector<int> profits7 = {10, 20, 30}; // 项目的利润
    vector<int> capital7 = {0, 5, 10}; // 项目的启动资金

    int result7 = solution.findMaximizedCapital(k7, w7, profits7, capital7);
    cout  << result7 << endl; // 输出结果

    return 0;
}





















