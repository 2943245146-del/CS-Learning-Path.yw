#include<iostream>
using namespace std;
//双链表的模拟实现;26.3.6
const int N=1e3+10;
int e[N],pre[N],ne[N],id,h;
void push_front(int x)
{
    id++;
    e[id]=x;
    ne[id]=ne[0];
    pre[id]=0;
    ne[0]=id;
    pre[ne[id]]=id;
}
void print()
{
    for(int i=ne[0];i;i=ne[i])
    {
        cout<<e[i]<<" ";
    }
    cout<<endl<<endl;
}
void insert(int k,int x)
{
    id++;
    e[id]=x;
    ne[id]=ne[k];
    pre[id]=k;
    ne[k]=id;
    pre[ne[id]]=id;
}
void insert_front(int k,int x)
{
    id++;
    e[id]=x;
    ne[id]=k;
    pre[id]=pre[k];
    ne[pre[k]]=id;
    pre[k]=id;
}
void erase(int k)
{
    ne[pre[k]]=ne[k];
    pre[ne[k]]=pre[k];
}
int main()
{
    for(int i=1;i<=5;i++)
    {
        push_front(i);
        print();
    }
    return 0;
}
