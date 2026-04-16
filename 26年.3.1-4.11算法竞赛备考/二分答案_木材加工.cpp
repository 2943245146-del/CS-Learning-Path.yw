//木材加工
#include<iostream>
using namespace std;
const int N=1e5+10;
int n,m;
int a[N];
int calc(int x)
{
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        ret+=a[i]/x;
    }
    return ret;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int left=1;
    int right=1e5;
    while(left<right)
    {
        int mid=left+right+1>>1;
        if(calc(mid)>=m) left=mid;
        else right=mid-1;
    }
    cout<<left<<endl;
    return 0;
}