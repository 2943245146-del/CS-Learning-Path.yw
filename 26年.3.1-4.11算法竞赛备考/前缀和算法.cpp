#include<iostream>
using namespace std;
//前缀和
int n,q;//数组长度和查询次数
const int N=1e5+10;
long long a[N],f[N];//a数组存储输入的数，f数组存储前缀和
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i];//前缀和数组的定义，f[i]表示前i个数的和
    }
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<f[r]-f[l-1]<<endl;//查询区间[l,r]的和等于前缀和f[r]减去前缀和f[l-1]，因为f[l-1]表示前l-1个数的和，所以f[r]-f[l-1]就是从l到r的数的和
    }
    return 0;
}