#include<iostream>
#include<cstring>
using namespace std;
const int N=1010;
int v[N],w[N];
int f[N][N];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=v[i]) f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
        }
    }
    cout<<f[n][m]<<endl;
    memset(f,-0x3f,sizeof f);
    f[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=v[i]) f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
        }
    }
    if(f[n][m]<0) cout<<0<<endl;
    else cout<<f[n][m]<<endl;
    return 0;
}