//模版题唯一的雪花
#include<iostream>
#include<unordered_map>
using namespace std;
const int N=1e6+10;
unordered_map<int, int> mash;//哈希表，记录每个元素出现的次数
int a[N];
int T,n;
int main()
{
        cout<<"开始了"<<endl;
    cin>>T;
while(T--)
{
    int cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int left=1;
    int right=1;
    while(right<=n)
    {
        
mash[a[right++]]+=1;
        while(mash[a[right-1]]>1)
        {
            mash[a[left++]]--;
}
cnt=max(cnt,right-left);
    }
    cout<<cnt<<endl;
    mash.clear();
    
}
return 0;
}
//模版题唯一的雪花
//#include<iostream>
//#include<unordered_map>
//using namespace std;
//const int N=1e6+10;
//unordered_map<int, int> mash;
//int a[N];
//int T,n;
//int main()
//{
//        cout<<"开始了"<<endl;
//    cin>>T;
//while(T--)
//{
//    int cnt=0;
//    cin>>n;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>a[i];
//    }
//    int left=1;
//    int right=1;
//    while(right<=n)
//    {
//        
//if(mash[a[right]]<1) mash[a[right++]]++;//如果a[right]是重复的，那么if永远不成立，while永远不成立，陷入死循环；
//    if(mash[a[right-1]]==1)
//    {
//        cnt=max(cnt,right-left);
//        while(mash[a[right-1]]>1)
//        {
//            mash[a[left++]]--;
//}
//}
//    }
//    cout<<cnt<<endl;
//    mash.clear();
//}
//return 0;
//}
