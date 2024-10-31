#include<bits/stdc++.h>

using namespace std;

void sortStack(vector<int>& stack);
int deep(vector<int>& stack);
int getMaxVal(vector<int>& stack, int deep);
int times(vector<int>& stack, int deep, int maxVal);
void down(vector<int>& stack, int deep, int maxVal, int times);

int main()
{
    return 0;
}

void sortStack(vector<int>& stack)
{
    int deep =  deep(stack);
    while (deep > 0)
    {
        int maxVal = getMaxVal(stack, deep);
        int k = times(stack, deep, maxVal);
        down(stack, deep, maxVal, k);
        deep -= times;
    }
}

// 返回栈的深度 但不改变当前栈的状态
int deep(vector<int>& stack)
{
    if (stack.empty())
    {
        return 0;
    }

    int cur = stack.top();
    stack.pop();
    int deep = deep(stack) + 1;
    stack.push(cur);
    return deep;
}

// 得到当前深度的最大值
int getMaxVal(vector<int>& stack, int deep)
{
    if (deep == 0) 
    {
        return INT_MIN;
    }
    int num = stack.top();
    stack.pop();
    int lowerMaxVal = getMaxVal(stack, deep - 1);
    int res = max(num, lowerMaxVal);
    stack.push(num);
    return res;
}

// 得到当前深度的最大值的个数
int times(vector<int>& stack, int deep, int maxVal)
{
    if (deep == 0)
    {
        return 0;
    }
    int num = stack.top();
    stack.pop();
    int lowerTimes = times(stack, deep - 1, maxVal);
    int res = num == maxVal ? lowerTimes + 1 : lowerTimes;
    stack.push(num);
    return res;
}

// 把所有最大值放到栈最底部 但其他数据次序不变
void down(vector<int>& stack, int deep, int maxVal, int times)
{
    if (deep == 0)
    {
        for (int i = 0; i < k; ++i)
        {
            stack.push(maxVal);
        }
    }
    else
    {
        int num = stack.top();
        stack.pop();
        deep(stack, deep - 1, maxVal, times);
        if (num != maxVal)
        {
            stack.push(num);
        }
    }
}



