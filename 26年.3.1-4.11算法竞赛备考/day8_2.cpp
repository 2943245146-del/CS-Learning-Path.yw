#include<iostream>
#include<ctime>
using namespace std;
const int N=1e5+10;
int a[N];
//快速排序
int get_dnom(int l,int r)
{
    return a[rand()%(r-l+1)+l];
}
void quick_sort(int l,int r)
{
    if(r<l) return;
    int p=get_dnom(l,r);
    int x=l,y=l,z=r;
    while(y<=z)
    {
        if(a[y]<p)
        {
            swap(a[y],a[x]);
                x++;
                y++;
        }
        else if(a[y]>p)
        {
            swap(a[y],a[z]);
            z--;
        }
        else
        {
            y++;
        }
    }
    quick_sort(l,x-1);
    quick_sort(z+1,r);
}
int main()
{
    srand((unsigned int)time(0));
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quick_sort(0,n-1);
    for(int i=0;i<n;i++)
    {
        cout << a[i]<<" ";
    }
    return 0;
}