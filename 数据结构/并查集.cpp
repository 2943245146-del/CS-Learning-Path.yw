//P16237 [蓝桥杯 2026 省 B] 应急布线
#include<iostream>
#include<cmath>
using namespace std;
const int N=1e5+10;
int n,m;
int f[N];
int find(int a)
{
    if(f[a]==a)
    {
        return a;
    }
    return f[a]=find(f[a]);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)//初始化并查集，每个节点的父节点初始为自己
    {
        f[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        f[find(a)]=find(b);//将a和b所在的集合合并，即将a所在集合的父节点指向b所在集合的父节点
    }
    for(int i=0;i<n;i++)
    {
        f[i]=find(i);//路径压缩，将每个节点的父节点直接指向根节点，优化后续的查询效率
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(f[i]==i)
        {
            cnt++;//统计集合的数量，即不同的父节点的数量
        }
    }
    cout<<cnt-1<<" "<<ceil(2.0*(cnt-1)/n)<<endl;
    return 0;
}