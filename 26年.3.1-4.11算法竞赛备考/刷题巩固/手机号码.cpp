#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
LL l,r;
bool check(LL x)
{
    string s=to_string(x);
    int a=0;
    int b=0;
    for(auto& e:s)
    {
        if(e=='8') a=1;
        if(e=='4') b=1;
        if(a==1&&b==1) return false;
    }
    int i=0;
    int j=1;
    while(i<s.size()&&j<s.size())
    {
        while(s[j]==s[i])
        {
            if(j-i+1==3) return true;
            j++;
        }
        i=j;
        j++;
    }
    return false;
}
int main()
{
    cin>>l>>r;
    LL cnt=0;
    while(l<=r)
    {
        if(check(l)) cnt++;
        l++;
    }
    cout<<cnt<<endl;
    return 0;
}