#include<iostream>
using namespace std;
//栈的模拟实现;26.3.7
const int N=1e3+10;
int stk[N],n;
void push(int x)
{
    stk[++n]=x;
}
void pop()
{
    n--;
}
int top()
{
    return stk[n];
}
bool empty()
{
    return n==0;
}
int main()
{
    for(int i=1;i<=10;i++)
    {
        push(i);
    }
    while(!empty())
    {
        cout << top() << " ";
        pop();  
    }
}