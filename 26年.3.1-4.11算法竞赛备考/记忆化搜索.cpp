#include<iostream>
using namespace std;
const int N=100;
int memo[N];
int dfs(int n)
{
if(memo[n]!=-1) return memo[n];
if(n==0||n==1) return n;
memo[n]=dfs(n-1)+dfs(n-2);
return memo[n];
}
int main()
{
    memset(memo,-1,sizeof memo);
    int n;
    cin>>n;
    cout<<dfs(n)<<endl;
    return 0;
}