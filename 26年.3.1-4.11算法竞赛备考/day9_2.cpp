//高精度算法模拟
#include <iostream>
const int N=1e6+10;
int a[N],b[N],c[N];
int la,lb,lc;
using namespace std;
void add(int c[],int a[],int b[])//高精度加法
{
    for(int i=0;i<lc;i++)
    {
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    if(c[lc]!=0)
    {
        lc++;
    }
}
int main()
{
    string x,y;
    cin>>x>>y;
    //将字符串转化为数组
    la=x.size();
    lb=y.size();
    lc=max(la,lb);
    for(int i=0;i<la;i++)
    {
        a[la-i-1]=x[i]-'0';
    }
    for(int i=0;i<lb;i++)
    {
        b[lb-i-1]=y[i]-'0';
    }
    add(c,a,b);
    for(int i=lc-1;i>=0;i--)
    {
        cout<<c[i];
    }
    return 0;
}