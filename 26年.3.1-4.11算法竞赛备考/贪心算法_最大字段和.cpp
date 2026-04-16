#include<iostream>
using namespace std;
//最大子段和算法题
const int N=2e5+10;
typedef long long ll;
int n;
int a[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
    }
    ll ret=-1e5;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];//当前子段和
        ret=max(ret,sum);//更新最大子段和
        if(sum<0) sum=0;//如果当前子段和小于0，重置为0，开始新的子段计算
    }
    cout <<ret<<endl;
    return 0;
}