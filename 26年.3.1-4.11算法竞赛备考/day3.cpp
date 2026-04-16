#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//默认升序排序
// int main()
// {
//     string s="abdwiefiewhfiw";
//     sort(s.begin(),s.end());
//     cout << s << endl;
//     int arr[]={1,32,4,1,4,56,7,8,43};
//     int sz=sizeof(arr)/sizeof(arr[0]);
//     sort(arr,arr+sz);
//     for(int i=0;i<sz;i++)    {
//         cout << arr[i] << " ";
//     }   
//     return 0;
// }
bool compare(int a,int b)
{
    return a>b;//降序排序compare引用
}
int main()
{
    int arr[]={1,32,4,1,4,56,7,8,43};
    int sz=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+sz,compare);
    for(int i=0;i<sz;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}