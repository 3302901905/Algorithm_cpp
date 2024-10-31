#include<bits/stdc++.h>

using namespace std;

// 用递归去逆序一个栈

// 栈底元素移除掉 上面元素盖下来
// 返回移除掉的底层元素
int BottomOut(stack<int>& s)
{
    int result = s.top();
    s.pop();
    if(s.empty())
    {
        return result;
    }
    else
    {
        int last = BottomOut(s);
        s.push(result);
        return last;
    }
}

// reverse
void Reverse(stack<int>& s)
{
    if(s.empty())
    {
        return;
    }
    int last = BottomOut(s);
    Reverse(s);
    s.push(last);
}







