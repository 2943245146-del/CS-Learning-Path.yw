#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e6+10;
int n,m;
struct node
{
    int a;
    int b;
}p[N];
bool cmp(node& x,node& y)
{
    return x.a<y.a;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>p[i].a>>p[i].b;
    sort(p+1,p+m+1,cmp);
    int ret=0,sum=0;
    for(int i=1;i<=m;i++)
    {
        int v=min(p[i].b,n-sum);
        ret+=p[i].a*v;
        sum+=v;
    }
    cout<<ret<<endl;
    return 0;
}