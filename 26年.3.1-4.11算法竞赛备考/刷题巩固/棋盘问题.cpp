#include<iostream>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    int x=0,y=0;
    for(int x1=0;x1<n;x1++)
    {
        for(int y1=0;y1<m;y1++)
        {
            for(int x2=x1+1;x2<=n;x2++)
            {
                for(int y2=y1+1;y2<=m;y2++)
                {
                    if(y2-y1==x2-x1) x++;
                    else y++;
                }
            }
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}