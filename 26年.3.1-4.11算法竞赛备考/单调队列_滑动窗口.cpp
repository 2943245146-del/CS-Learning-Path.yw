#include<iostream>
#include<deque>
using namespace std;
const int N=1e6+10;
int n,k;
int a[N];
int ret[N];
int ret2[N];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    deque<int> q;
    deque<int> q2;//可以用q.clear()清空;
    for(int i=1;i<=n;i++)
    {
        while(q.size()&&a[i]<=a[q.back()]) q.pop_back();
        while(q.size()&&(i-q.front()+1>k)) q.pop_front();
                q.push_back(i);
                if(i>=k) ret[i]=a[q.front()];
    }
        for(int i=1;i<=n;i++)
    {
        while(q2.size()&&a[i]>=a[q2.back()]) q2.pop_back();
        while(q2.size()&&(i-q2.front()+1>k)) q2.pop_front();
                q2.push_back(i);
                if(i>=k) ret2[i]=a[q2.front()];
    }
    for(int i=k;i<=n;i++) cout<<ret[i]<<" ";
    cout<<endl;
    for(int i=k;i<=n;i++) cout<<ret2[i]<<" ";
    cout<<endl;
    return 0;
}