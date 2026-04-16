#include<iostream>
using namespace std;
// int main()
// {
//     string s="hello world hello everyone";
//     string ss="llo";
//     size_t n=s.find(ss);
//     cout << n <<endl;
//     size_t n2=s.find(ss,n+1);
//     cout << n2 <<endl;
//     return 0;
// }
// int main()
// {
//     string s="hello world hello everyone";
//     size_t n=s.find("world",0,3);
//     cout << n <<endl;
//     size_t n2=s.find("everyday",n+1,5);
//     cout << n2 <<endl;
//     return 0;
// }
// int main()
// {
//     string s="hello world hello everyone";
//     size_t n=s.find("world",0,3);
//     if(n==string::npos)
//     {
//         cout << "not found" << endl;
//     }
//     else
//     {
//         cout << "found at pos:" << n << endl;
//     }
//     return 0;
// }
//sustr()函数，不传参数默认从0开始截取到字符串末尾；substr(pos)从pos开始截取到字符串末尾；substr(pos,len)从pos开始截取len个字符；
//stoi(str,&pos,进制)函数：将字符串转换为整数；stod()函数：将字符串转换为浮点数；to_string()函数：将数字转换为字符串；
//stol()函数：将字符串转换为长整数；
int main()
{
    ios::sync_with_stdio(false);//加速输入输出
    cin.tie(0);//解除cin和cout的绑定，进一步加速输入输出
    //竞赛中数据量大于10^6时，建议使用printf和scanf进行输入输出，因为它们比cin和cout更快
    return 0;
}