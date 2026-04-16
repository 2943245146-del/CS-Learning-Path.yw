#include<iostream>
using namespace std;
const int N=5010;
int n;
int a[N];
int f[N];
int main()
{
    int ret=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        f[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i])
            {
                f[i]=max(f[i],f[j]+1);
            }
        }
        ret=max(ret,f[i]);
    }
    cout<<ret<<endl;
    return 0;
}