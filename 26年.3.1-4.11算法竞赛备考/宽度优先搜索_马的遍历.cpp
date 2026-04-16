#include<iostream>
#include<cstring>
#include<deque>
using namespace std;
const int N=410;
int n,m,x,y;
int dist[N][N];
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};
void bfs()
{ 
    deque<pair<int,int>> q;
    q.push_back({x,y});
    dist[x][y]=0;
    while(q.size())
    {
        auto t=q.front();q.pop_front();
        int f1=t.first;int f2=t.second;
        for(int i=0;i<8;i++)
        {
            int x=f1+dx[i];
            int y=f2+dy[i];
                if(x<1||x>n||y<1||y>m) continue;
                if(dist[x][y]!=-1) continue;
            dist[x][y]=dist[f1][f2]+1;
            q.push_back({x,y});
        }
}
}
int main()
{
    cin>>n>>m>>x>>y;
    memset(dist,-1,sizeof(dist));
    bfs();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<< dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}