#include<iostream>
using namespace std;
class Employee; //前向声明Employee类，使Admin类能够使用Employee类的引用作为参数
class Admin  
{  
public:
    int GetAge(Employee& e);//声明Admin类的GetAge函数，使其能够访问Employee类的私有成员
};
class Employee  
{  
private:
    int age;
    friend int Admin::GetAge(Employee& e);//将Admin类的GetAge函数声明为Employee类的友元函数，使Admin类的GetAge函数能够访问Employee类的私有成员
public:
    Employee(int a)
    {        age=a+5;
    }
    int GetAge()
    {        return age;
    }
};
int Admin::GetAge(Employee& e)//定义Admin类的GetAge函数
{
    return e.age-5;//直接访问Employee类的私有成员age获取加密后的年龄，再减去5得到真实年龄
}
int main()  
{   Employee a(65), b(19), c(43), d(80);  
    cout<<a.GetAge()<<","<<b.GetAge()<<","<<c.GetAge()<<","<<d.GetAge()<<endl;//输出加密后的年龄  
    Admin m;  
    cout<<m.GetAge(a)<<","<< m.GetAge(b)<<","<< m.GetAge(c)<<","<< m.GetAge(d)<<endl;//输出真实年龄  
    return 0;  
}