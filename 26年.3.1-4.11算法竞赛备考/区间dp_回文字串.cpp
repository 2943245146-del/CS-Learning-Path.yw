#include<iostream>
using namespace std;
const int N=1010;
int f[N][N];
int main()
{
    string s;cin>>s;
    int n=s.size();
    for(int len=1;len<=n;len++)
    {
        for(int i=0;i+len-1<n;i++)
        {
            int j=i+len-1;
            if(s[i]==s[j]) f[i][j]=f[i+1][j-1];
            else f[i][j]=min(f[i+1][j],f[i][j-1])+1;
        }
    }
    cout<<f[0][n-1]<<endl;
    return 0;
}