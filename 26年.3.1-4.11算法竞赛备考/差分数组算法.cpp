//差分数组算法
#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],f[N];
int n,m;
int main()
{
    cin>>n>>m;
    //利用差分数组定义创建差分数组
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=a[i]-a[i-1];
    }
    while(m--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        f[l]+=k;
        f[r+1]-=k;
    }
    //还原出原数组
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+f[i];
        cout<<a[i]<<" ";
    }
    for(int i=1;i<=n;i++)
    {
        f[i]+=f[i-1];
        cout <<f[i]<<" ";
    }
    return 0;
}