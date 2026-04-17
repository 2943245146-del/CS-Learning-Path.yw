//以面向对象的概念，建立如下一个系统，每一名员工都有一个private权限的年龄，能通过GetAge()询问其年龄，GetAge()的回答加密规则为：age+5
//但管理员Admin能够获知每个员工的真实年龄。主函数和Employee类的设计如下，请写出管理员Admin类如何获知员工的真实年龄的思路，并给出相应的代码。
#include <iostream>
using namespace std;
class Employee  
{  
private:
    int age;
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
        return e.GetAge()-5;//直接访问Employee类的GetAge函数获取加密后的年龄，再减去5得到真实年龄
    }
};
int main()  
{   Employee a(65), b(19), c(43), d(80);  
    cout<<a.GetAge()<<","<<b.GetAge()<<","<<c.GetAge()<<","<<d.GetAge()<<endl;//输出加密后的年龄  
    Admin m;  
    cout<<m.GetAge(a)<<","<< m.GetAge(b)<<","<< m.GetAge(c)<<","<< m.GetAge(d)<<endl;//输出真实年龄  
    return 0;  
} 