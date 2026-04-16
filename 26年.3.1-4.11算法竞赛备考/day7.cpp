#include<iostream>
#include<vector>
using namespace std;
//vector模拟树的存储
const int N=1e3+10;
int n;
bool st[N];
vector<int> g[N];
void dfs(int u)//实现深度优先搜索
{
    st[u]=true;
    cout << u << " ";
    for(int v:g[u])
    {
        if(!st[v])
        {
            dfs(v);
        }
    }
}
void bfs(int u)//实现广度优先搜索
{
    st[u]=true;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        cout << t << " ";
        for(int v:g[t])
        {
            if(!st[v])
            {
                st[v]=true;
                q.push(v);
            }
        }
    }
}
void bfs2(int u)//利用deque实现广度优先搜索
{
    st[u]=true;//标记访问过的节点
    deque<int> q;
    q.push_back(u);//将起始节点加入队列
    while(!q.empty())//当队列不为空时继续搜索
    {
        int t=q.front();//获取队列头部的节点
        q.pop_front();//将头部节点出队
        cout << t << " ";
        for(int v:g[t])//遍历当前节点的邻接节点
        {
            if(!st[v])
            {
                st[v]=true;//标记邻接节点为已访问
                q.push_back(v);
            }
        }
    }
}
int main()
{
    cin>>n;//输入节点
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    return 0;
}