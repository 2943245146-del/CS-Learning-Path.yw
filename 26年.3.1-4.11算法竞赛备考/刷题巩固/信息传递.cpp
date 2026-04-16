#include<iostream>
#include<deque>
using namespace std;
const int N=2e5+10;
int n,cnt;
int ret=0x3f3f3f3f;
int ne[N],v[N];//ne,入度
bool st[N];
void dfs(int x)
{
    if(st[x]) return;
    cnt++;
    st[x]=true;
    dfs(ne[x]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ne[i];
        v[ne[i]]++;
    }
    deque<int> p;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0) p.push_back(i);
    }
    while(p.size())
    {
        int t=p.front();
        p.pop_front();
        st[t]=true;
        v[ne[t]]--;
        if(v[ne[t]]==0) p.push_back(ne[t]);
    }
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        if(!st[i])
        {
            dfs(i);
            ret=min(ret,cnt);
        }
    }
    cout<<ret<<endl;
    return 0;
}