#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ULL;//使用无符号长长整型来存储哈希值，避免负数问题
const int N=1e4+10;
int n;
int p=131;//选择一个较大的质数作为哈希基数，常用的有131、13331等，可以根据实际情况选择
ULL a[N];
ULL get_hash(string& s)
{
    ULL ret=0;
    for(int i=1;i<=s.size();i++)//从1开始，方便后续计算哈希值
    {
        ret=ret*p+s[i-1];//哈希值的计算方式，常用的有多项式滚动哈希等，这里使用简单的乘法加法方式
    }
    return ret;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        a[i]=get_hash(s);
    }
    int ret=1;
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1]) ret++;
    }
    cout<<ret<<endl;
    return 0;
}