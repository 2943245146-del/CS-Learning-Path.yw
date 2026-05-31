/*设有一个Document类，有数据成员name，从Document类派生出Book类，增加了数据成员PageCount，这2个类都定义了Show函数输出其数据成员。请补充Book类的定义，并分析用例输出为什么是这样的运行结果。*/
#include <iostream>  
using namespace std;  
class Document  
{  
protected:  
    string name;  
public:  
    Document(const string &p)  
    {  
        name=p;  
    }  
    void Show()  
    {  
        cout<<name<<endl;  
    }     
};  
class Book:public Document  
{  
public:  
    Book(const string &p,int c):Document(p),PageCount(c){}  
    void Show()  
    {
        Document::Show();
        cout<<"PageCount="<<PageCount<<endl;
    }  
private:  
    int PageCount;  //页数  
};
int main()  
{ Document a("Document1");  
Book b("Book1",100);  
a.Show();  
b.Show();  
a=b;  
a.Show();  
return 0;  
}  