/*从键盘输入要读入的文件名，如果是grade.txt，则输出文件内容。如果不是grade.txt,则输出文件打开失败（本题要求用异常处理机制来实现）*/
#include<iostream> 
#include<string>
#include<fstream>
using namespace std;
int main()
{    string filename;
    cin>>filename;
    ifstream file(filename);
    try
    {        if(!file.is_open())
        {            throw runtime_error("文件打开失败");//抛出一个运行时错误异常，异常信息
        }
        string line;
        while(getline(file,line))
        {            cout<<line<<endl;
        }        file.close();
    }
    catch(const runtime_error& e)
    {        cout<<e.what()<<endl;//输出异常信息
    }
    return 0;
}