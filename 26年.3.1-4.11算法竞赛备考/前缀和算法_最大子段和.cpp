#include<iostream>
using namespace std;
//最大子段和算法题
typedef long long ll;
const int N=1e5+10;
ll f[N];//前缀和数组
int n;//数组长度
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        f[i]=f[i-1]+x;//前缀和数组的定义，f[i]表示前i个数的和
    }
    ll ret=-1e5;//记录最大差值
    ll previn=0;//记录前缀和的最小值
    for(int i=1;i<=n;i++)
    {
        ret=max(ret,f[i]-previn);//当前前缀和减去之前的最小前缀和就是当前的差值，更新最大差值
        previn=min(previn,f[i]);//更新前缀和的最小值
    }
    cout <<ret<<endl;
    return 0;
}
