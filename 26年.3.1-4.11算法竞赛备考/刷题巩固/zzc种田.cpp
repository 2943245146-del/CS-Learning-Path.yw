#include<iostream>
using namespace std;
const long long N=1e16+10;
typedef long long LL;
LL n,m;
LL ret=0;
void f(LL x,LL y)
{
    if(y==0) return;
    ret+=x/y*y*4;
    f(y,x%y);
}
int main()
{
    cin>>n>>m;
    if(n<m)
    {
        swap(n,m);
    }
    f(n,m);
    cout<<ret<<endl;
    return 0;
}
