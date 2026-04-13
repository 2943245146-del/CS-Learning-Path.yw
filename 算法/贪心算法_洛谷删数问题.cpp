#include<iostream>
using namespace std;
string s;
int n;
int main()
{
    cin>>s>>n;
    for(int i=1;i<=n;i++)
    {
        bool flag=false;
        for(int j=0;j<s.size()-1;j++)
        {
            if(s[j]>s[j+1])
            {
                s.erase(j,1);
                flag=true;
                break;
            }
        }
        if(!flag) s.pop_back();
    }
    while(s.size()>1&&s[0]=='0') s.erase(0,1);
    cout<<s<<endl;
    return 0;
}