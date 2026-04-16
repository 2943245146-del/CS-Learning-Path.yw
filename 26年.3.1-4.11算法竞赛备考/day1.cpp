#include <iostream>
#include <string>
using namespace std;
// 1. 输入一行字符串，输出该字符串
// int main()
// {
//     string s;
//     getline(cin,s,'\n');
//     cout << s << endl;
//     return 0;
//  }
// int main()
// {
//     string s=" hello world ";
//     cout << s.size() << endl;
//     return 0;
// }
// int main()
// {
//     string s="abcdefg";
//     string::iterator it=s.begin();
//     string::iterator it2=s.end();
//     cout << *it << endl;
//     it++;
//     cout << *it << endl;
//     for(int i='a';i<='z';i++)
//     {
//         s.push_back(i);
//     }
//     s.pop_back();
//     string ss="abcdefg";
//     string str="xxx";
//     ss.insert(0,str);//ss.insert(0,'xxx')//ss.insert(0,3,'x')
//     cout << ss <<endl;
//     return 0;
// }
//find函数
// int main()
// {
//     string s="hello world";
//     int pos=s.find("world");//find("world",pos，len )
//     if(pos==-1)
//     {
//         cout << "not found" << endl;
//     }
//     else    {
//         cout << "found at pos:" << pos << endl;
//     }
//     return 0;
// }
//substr函数
int main()
{   string s="hello world";
    string sub=s.substr(0,5);//substr(pos,len)
    cout << sub << endl;
    return 0;
}