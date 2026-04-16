#include<iostream>
#include<vector>
using namespace std;
const int N=1010;
int n,m,cnt;
typedef pair<int,int> PII;
vector<PII> g[N];
int f[N][N];
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cnt=max(cnt,c);
        g[c].push_back({a,b});
    }
    for(int i=1;i<=cnt;i++)
    {
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            for(auto e:g[i])
            {
                if(j>=e.first) f[i][j]=max(f[i][j],f[i-1][j-e.first]+e.second);
            }
        }
    }
    cout<<f[cnt][m]<<endl;
    return 0;
}