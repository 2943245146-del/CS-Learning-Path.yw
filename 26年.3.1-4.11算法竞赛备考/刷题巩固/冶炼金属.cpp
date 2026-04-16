#include<iostream>
#include<vector>
using namespace std;
int n;
typedef pair<int,int> PLL;
vector<PLL> p;
bool check_min(int x)
{
    for(int i=0;i<n;i++)
    {
        int a=p[i].first;
        int b=p[i].second;
        if(a/x>b) return false;//x小一点就是错
    }
    return true;//x大了
}
bool check_max(int x)
{
    for(int i=0;i<n;i++)
    {
        int a=p[i].first;
        int b=p[i].second;
        if(a/x<b) return false;
    }
    return true;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        p.push_back({a,b});
    }
    int l=1,r=1e9+10;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check_min(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<" ";
    r=1e9+10;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check_max(mid)) l=mid;
        else r=mid-1;
    }
    cout<<r<<endl;
    return 0;
}