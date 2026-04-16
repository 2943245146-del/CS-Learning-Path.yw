#include<iostream>
using namespace std;
const int N=3e4+10;
int n,m;
int f[N];
int v[N],w[N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>v[i]>>w[i];
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=v[i];j--)
        {
            f[j]=max(f[j],f[j-v[i]]+v[i]*w[i]);
        }
    }
    cout<<f[n]<<endl;
    return 0;
}