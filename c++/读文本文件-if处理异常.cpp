#include<iostream> 
#include<string>
#include<fstream>
using namespace std;
/*从键盘输入要读入的文件名，如果是grade.txt，则输出文件内容。如果不是grade.txt,则输出文件打开失败（要求用if来处理文件打开失败）*/
int main()
{
    string filename;
    cin>>filename;
    ifstream file(filename);
    if(file.is_open())
    {
        string line;
        while(getline(file,line))
        {
            cout<<line<<endl;
        }
        file.close();
    }
    else
    {
        cout<<"文件打开失败"<<endl;
    }
    return 0;
}