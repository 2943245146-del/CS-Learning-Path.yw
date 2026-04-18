#include<iostream>
using namespace std;
class Employee  
{  
private:
    int age;
    friend class Admin;//将Admin类声明为Employee类的友元类，使Admin类能够访问Employee类的私有成员
public:
    Employee(int a)
    {        
        age=a+5;
    }
    int GetAge()
    {        
        return age;
    }
};
class Admin  
{
public:
    int GetAge(Employee& e)
    {
        return e.age-5;//直接访问Employee类的私有成员age获取加密后的年龄，再减去5得到真实年龄
    }
};
int main()  
{   Employee a(65), b(19), c(43), d(80);  
    cout<<a.GetAge()<<","<<b.GetAge()<<","<<c.GetAge()<<","<<d.GetAge()<<endl;//输出加密后的年龄  
    Admin m;  
    cout<<m.GetAge(a)<<","<< m.GetAge(b)<<","<< m.GetAge(c)<<","<< m.GetAge(d)<<endl;//输出真实年龄  
    return 0;  
}