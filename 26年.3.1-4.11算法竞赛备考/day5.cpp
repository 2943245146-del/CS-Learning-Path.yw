#include<iostream>
using namespace std;
//链表的模拟实现;26.3.6
//未来加餐动态链表的模拟实现；
const int N=1e3;
int e[N],ne[N],h,id;
void push_front(int x)
{
    id++;
    e[id]=x;
    ne[id]=ne[h];
    ne[h]=id;
}
void print()
{
    for(int i=ne[0];i;i=ne[i])
    {
        cout<<e[i]<<" ";
    }
    cout <<endl<<endl;
}
int find(int x)
{
    for(int i=ne[0];i;i=ne[i])
    {
        if(e[i]==x)
        {
            return i;
        }
    }
    return 0;
}
void insert(int k,int x)
{
    id++;
    e[id]=x;
    ne[id]=ne[k];
    ne[k]=id;
}
void erase(int k)
{
    if(ne[k])
    {
        ne[k]=ne[ne[k]];
    }
}//这个函数是删除链表中第k个元素的下一个元素，前提存在
void erase2(int x)//时间复杂度高，与尾删 尾插都不常用；
{
    if(e[ne[0]]==x)
    {
        ne[0]=ne[ne[0]];
        return;
    }
    for(int i=ne[0];i;i=ne[i])
    {
        if(e[ne[i]]==x)
        {
            ne[i]=ne[ne[i]];
        }
    }
}//解释一下，第一个if是用来判断如果是删除链表头的下一个元素，那么直接跳过，这是一个特殊情况；
//接下来开始遍历，如果遍历到一个元素的下一个元素是要删除的x，那么直接跳过下一个元素:
//e[i]是当前元素，e[ne[i]]是下一个元素，ne[i]是当下元素的下一个索引，ne[ne[i]]是下一个元素的下一个索引
int main()
{
for(int i=1;i<=5;i++)
{
    push_front(i);
    print();
}
cout <<find(1)<<endl;
cout <<find(2)<<endl;
cout <<find(6)<<endl;
insert(1,10);
print();
insert(2,100);
print();
erase(2);
print();
erase(4);
print();
return 0;
}