#include<iostream>
using namespace std;
int n;
int main()
{
    cin>>n;
    int chushi=1;
    int s=0;
    int m=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            s+=chushi;
            m++;
            if(m==n) break;
        }
        chushi++;
        if(m==n) break;
    }
    cout<<s<<endl;
    return 0;
}