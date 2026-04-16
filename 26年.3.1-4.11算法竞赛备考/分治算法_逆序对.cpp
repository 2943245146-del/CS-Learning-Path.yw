#include<iostream>
using namespace std;
const int N=1e5+10;
int n;
int a[N];
int temp[N];
long long merge(int l,int r)
{
    if(r<=l) return 0;
    long long ret=0;
    int mid=(l+r)/2;
    ret+=merge(l,mid);
    ret+=merge(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j]) 
        {
            temp[k++]=a[i++];//相等时不算逆序对
        }
        else
        {
            temp[k++]=a[j++];//当右边元素小于左边元素时，说明左边剩余的元素都大于右边这个元素，形成逆序对   
            ret+=mid-i+1;//逆序对数量等于左边剩余元素数量
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=r)
    {
        temp[k++]=a[j++];
    }
    for(int t=l;t<=r;t++)
    {
        a[t]=temp[t];
    }
    return ret;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<merge(1,n)<<endl;
    return 0;
}