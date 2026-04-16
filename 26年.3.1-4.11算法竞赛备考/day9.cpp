//矩阵填数问题
#include <iostream>
using namespace std;
int main()
{
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int n=0;
    cin>>n;
    int arr[100][100];
    arr[1][1]=1;
    int x=1;
    int y=1;
    int pos=0;
    for(int i=2;i<=n*n;i++)
    {
        if(x+dx[pos]==n+1||y+dy[pos]==n+1||x+dx[pos]==0||y+dy[pos]==0||arr[x+dx[pos]][y+dy[pos]]!=0)
        {
            pos=(pos+1)%4;
        }
        arr[x+dx[pos]][y+dy[pos]]=arr[x][y]+1;
        x+=dx[pos];
        y+=dy[pos];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
        printf("%3d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}