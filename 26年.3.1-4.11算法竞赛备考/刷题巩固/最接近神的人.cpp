#include<iostream>
using namespace std;
const int N=5e5+10;
typedef long long LL;
int n;
int a[N],temp[N];
LL merge_sort(int l,int r)
{
    if(l>=r) return 0;
    LL ret=0;
    int mid=(l+r)/2;
    ret+=merge_sort(l,mid);
    ret+=merge_sort(mid+1,r);
    int cur1=l;
    int cur2=mid+1;
    int i=l;
    while(cur1<=mid&&cur2<=r)
    {
        if(a[cur1]<=a[cur2]) temp[i++]=a[cur1++];
        else{
            ret+=mid-cur1+1;
            temp[i++]=a[cur2++];
        }
    }
    while(cur1<=mid)
    {
        temp[i++]=a[cur1++];
    }
    while(cur2<=r)
    {
        temp[i++]=a[cur2++];
    }
    for(int i=l;i<=r;i++)
    {
        a[i]=temp[i];
    }
    return ret;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1;
    int r=n;
    cout<<merge_sort(l,r)<<endl;
    return 0;
}