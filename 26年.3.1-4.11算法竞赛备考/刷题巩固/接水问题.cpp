#include<iostream>
#include<deque>
using namespace std;
int t,m,n;
deque<int> p;
deque<int> p2;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        if(i>m) p2.push_back(x);
        p.push_back(x);
    }
    while(1)
    {
        int f=0;
        t++;
    for(int i=0;i<m;i++)
    {
        p[i]--;
        if(p[i]==0&&p2.size())
        {
            p[i]=p2.front();
            p2.pop_front();
        }
        if(p[i]<=0) f++;
    }
    if(f==m) break;
}
cout<<t<<endl;
return 0;
}