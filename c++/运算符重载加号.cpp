#include<iostream>
using namespace std;
class person
{
    public:
    //成员函数重载运算符+
    person operator+(const person& p)
    {
        person temp;
        temp.m_A=this->m_A+p.m_A;
        temp.m_B=this->m_B+p.m_B;
        return temp;
    }
    int m_A;
    int m_B;
};
//全局函数重载运算符+
person operator+(const person& p1,const person& p2)
{    person temp;
    temp.m_A=p1.m_A+p2.m_A;
    temp.m_B=p1.m_B+p2.m_B;
    return temp;
}
//全局函数重载运算符+，参数类型不同
person operator+(const person& p1,int a)
{    person temp;
    temp.m_A=p1.m_A+a;
    temp.m_B=p1.m_B+a;
    return temp;
}
void test01()
{
    person p1;
    p1.m_A=10;
    p1.m_B=20;
    person p2;
    p2.m_A=100;
    p2.m_B=200;
    person p3=p1+p2;
    cout<<"p3.m_A="<<p3.m_A<<endl;
    cout<<"p3.m_B="<<p3.m_B<<endl;
}
int main()
{
    test01();
    return 0;
}