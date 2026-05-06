#include<iostream>
using namespace std;
class person
{
    public:
    person(string name,int age)
    {
        m_Name=name;
        m_Age=age;
    }
    string m_Name;
    int m_Age;
};
bool operator==(const person& p1,const person& p2)//重载==运算符，参数类型为person对象的引用
{
    if(p1.m_Name==p2.m_Name&&p1.m_Age==p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test01()
{
    person p1("张三",18);
    person p2("李四",20);
    if(p1==p2)
    {
        cout<<"p1和p2是同一个人"<<endl;
    }
    else
    {
        cout<<"p1和p2不是同一个人"<<endl;
    }
}
int main()
{    test01();
    return 0;
}