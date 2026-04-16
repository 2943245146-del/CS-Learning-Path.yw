#include<iostream>
#include<vector>
using namespace std;
int n,m,w,cnt;
const int N=1e4+10;
int c[N],d[N];
vector<int> p[N];
int cc[N],dd[N];
int f[N];
bool st[N];
void dfs(int i)
{
    st[i]=true;
    cc[cnt]+=c[i];
    dd[cnt]+=d[i];
        for(auto e:p[i])
        {
        if(!st[e]) dfs(e);
        }
}
int main()
{
cin>>n>>m>>w;
    for(int i=1;i<=n;i++) cin>>c[i]>>d[i];
    for(int i=0;i<m;i++)
    {int a,b;
     cin>>a>>b;
        p[a].push_back(b);
     p[b].push_back(a);
}
    for(int i=1;i<=n;i++)
    {
        if(!st[i]) 
        {
            cnt++;
            dfs(i);
        }
    }
    for(int i=1;i<=cnt;i++)
    {
for(int j=w;j>=cc[i];j--)
{
    f[j]=max(f[j],f[j-cc[i]]+dd[i]);
}
    }
    cout<<f[w]<<endl;
    return 0;
}