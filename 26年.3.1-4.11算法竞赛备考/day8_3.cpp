//归并排序
#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],temp[N];
void merge_sort(int l,int r)
{    if(r<=l) return;
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
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
    for(int i=l;i<=r;i++)
    {
        a[i]=temp[i];
    }
}