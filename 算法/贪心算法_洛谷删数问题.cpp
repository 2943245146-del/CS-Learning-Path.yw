// 洛谷P1096 洛谷删数问题
// 题目描述
// 给定一个由数字组成的字符串S和一个整数N，要求从S中删除N个数字，使得剩下的数字组成的数最小。输出删除后的结果
//思路：贪心算法，每次删除一个数字时，选择使得结果最小的删除位置
//时间复杂度:O(n*k)，其中n是字符串S的长度。每次删除一个数字需要遍历字符串一次，最多需要删除N个数字。
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