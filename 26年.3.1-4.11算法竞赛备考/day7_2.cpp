#include<iostream>
using namespace std;
//链式前向星模拟实现树的存储
const int N=1e5+10;
int h[N],e[N*2],ne[N*2],id;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;//a b之间有一个边;
        id++;
        e[id]=b;
        ne[id]=h[a];
        h[a]=id;
        id++;
        e[id]=a;
        ne[id]=h[b];
        h[b]=id;
    }
    return 0;
}