#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
list<int> p1,p2;
unordered_map<int,list<int>::iterator> mp1,mp2;
int n1,n2,m;
int main()
{
    cin>>n1>>n2>>m;
    while(m--)
    {
        int x;
        cin>>x;
        if(mp1.count(x))
        {
            p1.erase(mp1[x]);
            mp1.erase(x);
            p1.push_front(x);
            mp1[x]=p1.begin();
        }
        else if(mp2.count(x))
        {
            p2.erase(mp2[x]);
            mp2.erase(x);
            p1.push_front(x);
            mp1[x]=p1.begin();
        }
        else
        {
            p2.push_front(x);
            mp2[x]=p2.begin();
        }
        if(p1.size()>n1)
        {
            auto j=*p1.rbegin();
            p1.erase(mp1[j]);//可以用pop
            mp1.erase(j);
            p2.push_front(j);
            mp2[j]=p2.begin();
        }
        if(p2.size()>n2)
        {
            auto j=*p2.rbegin();
            p2.erase(mp2[j]);
            mp2.erase(j);
        }
    }
    for(auto x:p1) cout<<x<<" ";
    cout<<endl;
    for(auto x:p2) cout<<x<<" ";
    cout<<endl;
    return 0;
}