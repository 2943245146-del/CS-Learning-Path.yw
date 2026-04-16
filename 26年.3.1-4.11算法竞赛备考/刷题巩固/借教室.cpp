// TLE#include<iostream>
// using namespace std;
// const int N=1e6+10;
// int n,m;
// int d[N],v[N],fr[N],dd[N];
// int main()
// {
//     cin>>n>>m;
//     int t=0;
//     for(int i=1;i<=n;i++) cin>>d[i];
//     for(int i=1;i<=m;i++) cin>>v[i]>>fr[i]>>dd[i];
//     for(int i=1;i<=m;i++)
//     {
//         for(int j=fr[i];j<=dd[i];j++)
//         {
//             d[j]-=v[i];
//             if(d[j]<0) 
//             {
//                 cout<<-1<<endl;
//                 t=i;
//                 break;
//             }
//         }
//         if(t!=0) break;
// }
//     cout<<t<<endl;
//     return 0;
// }
#include<iostream>
using namespace std;
const int N=1e6+10;
int n,m;
int v[N],a[N],s[N],d[N];
int f[N];
bool check(int x)
{
    for(int i=1;i<=n;i++)
    {
        f[i]=v[i]-v[i-1];
    }
    for(int i=1;i<=x;i++)
    {
        f[s[i]]-=a[i];
        f[d[i]+1]+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i]+f[i-1];
        if(f[i]<0) return false;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=m;i++) cin>>a[i]>>s[i]>>d[i];
    int l=1;
    int r=m;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    if(l==m) cout<<0<<endl;
    else cout<<-1<<endl<<l<<endl;
    return 0;
}