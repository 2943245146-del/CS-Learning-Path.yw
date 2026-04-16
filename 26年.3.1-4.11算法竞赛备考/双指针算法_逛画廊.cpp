#include<iostream>
#include<unordered_map>
using namespace std;
int n,m;
const int N=1e6+10;
int a[N];
int main()
{
    cin>>n>>m;
    unordered_map<int,int> map;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int left=n;
    int right=n;
    int ret=n-1+1;
    int l,r=1;
    int cnt=0;
    while(left>0)
    {
        map[a[left]]++;
        if(map[a[left]]==1) cnt++;
        left--;
        while(cnt==m)
        {
            if(ret>=right-left)
            {
                ret=right-left;
                l=left+1;
                r=right;
            }
            map[a[right]]--;
            right--;
            if(map[a[right+1]]==0)
            {
                cnt--;
            }
        }
    }
    cout << l<<" "<<r<<endl;
    return 0;
}
