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
        c[i+1]+=c[i]/10;//进位
        c[i]%=10;
    }
    if(c[lc]!=0)
    {
        lc++;//如果最高位有进位，长度加1
    }
}
int main()
{
    string x,y;
    cin>>x>>y;
    //将字符串转化为数组
    la=x.size();
    lb=y.size();
    lc=max(la,lb);//长度为两数中较大的那个
    for(int i=0;i<la;i++)
    {
        a[la-i-1]=x[i]-'0';//将字符串的每一位转化为整数，存储在数组中，注意是逆序存储
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