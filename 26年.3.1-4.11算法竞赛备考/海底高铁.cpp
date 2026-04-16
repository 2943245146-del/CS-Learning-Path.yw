//海底高铁算法题
#include<iostream>
using namespace std;
const int N=1e5+10;
int n,m;
typedef long long ll;
ll a[N],f[N];
int main()
{
    cin>>n>>m;
    //1存节点2差分次数3累计
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
    }
    ll ret=0;
    for(int i=1;i<m;i++)
    {
        int l=a[i];
        int r=a[i+1];
        if(l>r) swap(l,r);
        f[l]++;
        f[r]--;
    }
    for(int i=1;i<=n;i++)
    {
        f[i]+=f[i-1];
    }
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ret+=min(a*f[i],b*f[i]+c);
    }
    cout<<ret<<endl;
    return 0;
}