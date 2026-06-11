/*设有一个Document类，有数据成员name，从Document类派生出Book类，增加了数据成员PageCount，这2个类都定义了Show函数输出其信息。*/
#include <iostream>  
#include <string>  
using namespace std;  
class Document  
{  
protected:  
    string name;  
public:  
    Document(const string &p)  
    {   name=p;  
        cout<<"Document constructor was called"<<endl;  
    }  
     virtual void Show()  
    {   cout<<name<<endl;   }     
  
     virtual ~Document()  
     {  }  
};  
class Book:public Document  
{  
private:  
    int PageCount;  
public:  
    Book(const string &p,int c):Document(p),PageCount(c)  
    {   cout<<"Book constructor was called"<<endl;  }  
    virtual void Show()  
    {   cout<<name<<","<<PageCount<<endl;  }  
    virtual ~Book()  
    {  }  
};
int main()  
{   
 string s;  
 int a;  
 cin>>s>>a;  
 Book b(s,a);  
 Document &d=b;  
 d.Show();  
 return 0;  
} 
/*测试输入帮助，input (新窗口)	期待的输出帮助，expectedoutput (新窗口)	时间限制帮助，timelimit (新窗口)	内存限制帮助，memlimit (新窗口)	额外进程帮助，nproc (新窗口)
测试用例 1	以文本方式显示
Java↵
35↵
以文本方式显示
Document constructor was called↵
Book constructor was called↵
Java,35↵
无限制	64M	0
*/