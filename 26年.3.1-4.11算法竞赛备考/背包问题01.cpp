#include<iostream>
#include<cstring>
using namespace std;
const int N=1010;
int n,m;
int v[N],w[N];
int f[N][N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=v[i])
            {
                f[i][j]=max(f[i][j],w[i]+f[i-1][j-v[i]]);//状态转移方程
            }
        }
    }
    cout<<f[n][m]<<endl;//最大价值
    memset(f,-0x3f,sizeof(f));//非法初始化
    f[0][0]=0;
        for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=v[i])
            {
                f[i][j]=max(f[i][j],w[i]+f[i-1][j-v[i]]);//状态转移方程
            }
        }
    }
    if(f[n][m]<0) cout<<0<<endl;
    else cout<<f[n][m]<<endl;//满足最大容量的最大价值
    return 0;
}
