#include<bits/stdc++.h>

using namespace std;

// 含有嵌套的表达式求值

int where = 0;

int calculate(string & str)
{
    return process(str. 0); 
}

// s[i ... ] : 遇到字符串终止 或者 遇到右括号 停止
// 返回自己负责的那一段计算的结果
// 返回之前要更新全局变量where
// 为了上游函数直到从哪里继续
int process(string& str, int i)
{
    int cur = 0;
    vector<int> numbers;
    vector<char> ops;
    while (i < str.size() && str[i] != ')')
    {
        if (s[i] >= '0' && str[i] <= '9')
        {
            cur = cur * 10 + (str[i++] - '0');
        }
        else if (str[i] != '(')
        {
            // 遇到了运算符
            push(numbers, ops, cur, s[i++]);
            cur = 0;
        }
        else 
        {
            cur = process(str, i + 1);
            i = where + 1;
        }
    }

    push(numbers, ops, cur, '+');
    where = i;
    return compute(numbers, ops);

}

void push(vector<int>& numbers, vector<char>& ops, int num, char op)
{
    int n = numbers.size();
    if (n == 0 || ops[n - 1] == '+' || ops[n - 1] == '-')
    {
        numbers.push_back(num);
    }
    else 
    {
        int number = numbers.back();
        numbers.pop_back();
        char curOps = ops.back();
        ops.pop_back();
        if (curOps == '*')
        {
            numbers.push_back(number * num);
        }
        else
        {
            numbers.push_back(number / num);
        }
    }

    ops.push_back(op);

}

int compute(vector<int>& numbers, vector<char>& ops)
{
    int res = numbers[0];
    for (int i = 0; i < ops.size(); i++)
    {
        if (ops[i] == '+')
        {
            res += numbers[i + 1];
        }
        else
        {
            res -= numbers[i + 1];
        }
    }
    return res;
}


int main()
{
    return 0;
}

