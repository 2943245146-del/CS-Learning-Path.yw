#include<iostream>
#include<ctime>
using namespace std;
const int N=1e5+10;
int a[N];
void inster_sort(int arr[],int sz)
{
    for(int i=1;i<sz;i++)
    {
        int t=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>t)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=t;
    }
}
void selection_sort(int arr[],int sz)
{
    for(int i=0;i<sz-1;i++)
    {
        int k=i;
        for(int j=i+1;j<sz;j++)
        {
            if(arr[j]<arr[k])
            {
                k=j;
            }
        }
        swap(arr[i],arr[k]);
    }
}
void bubble_sort(int arr[],int sz)
{
    for(int i=0;i<sz-1;i++)
    {
        for(int j=0;j<sz-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void heap_sort(int arr[],int sz)//*** */
{
    for(int i=sz/2-1;i>=0;i--)
    {
        heapify(arr,sz,i);
    }
    for(int i=sz-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void heapify(int arr[],int sz,int u)
{
    int t=u;
    int l=2*u+1;
    int r=2*u+2;
    if(l<sz&&arr[l]>arr[t])
    {
        t=l;        
    }
    if(r<sz&&arr[r]>arr[t])
    {
        t=r;
    }
    if(t!=u)
    {
        swap(arr[u],arr[t]);
        heapify(arr,sz,t);  
    }
}
int main()
{
    srand(time(0));
    return 0;
}