#include<iostream>
using namespace std;
int n;
int main()
{
    cin>>n;
    int i=0;
    while(1)
    {
       if(n%(2<<i)!=0&&n/(2<<i)==0) 
        {
            break;
        } 
        i++;
    }
    int t=i;
    int m=n;
    while(1)
    {
        i--;
        if(i<0)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(n-(2<<i)<0) continue;
        n=n-(2<<i);
        if(n==0) break;
    }
    while(1)
    {
        t--;
        if(m-(2<<t)<0) continue;
        m=m-(2<<t);
        cout<<(2<<t)<<" ";
        if(m==0) break;
    }
    return 0;
}