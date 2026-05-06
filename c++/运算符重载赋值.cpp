#include<iostream>
using namespace std;
class person
{
    public:
    person(int age)
    {
        m_age=new int(age);//动态分配内存，存储年龄
    }
    int *m_age;
    person& operator=(const person& p)//重载赋值运算符，参数类型为person对象的引用
    {
        if(m_age!=NULL)//如果当前对象的年龄指针不为空，那么就先释放当前对象的年龄指针指向的内存
        {
            delete m_age;
            m_age=NULL;
        }
        m_age=new int(*p.m_age);//动态分配内存，存储年龄，把p对象的年龄值赋给当前对象的年龄值
        return *this;//返回当前对象的引用
    }
};
void test01()
{
    person p1(18);
    person p2(20);
    person p3(30);
    p3=p2=p1;//浅拷贝，p2的m_age指针指向p1的m_age指针，导致两个对象共享同一块内存，修改其中一个对象的年龄会影响另一个对象的年龄
    cout<<"年龄："<<*p1.m_age<<endl;//输出年龄
    cout<<"年龄："<<*p2.m_age<<endl;//输出年龄
    cout<<"年龄："<<*p3.m_age<<endl;//输出年龄
}
int main()
{
    test01();
    return 0;
}