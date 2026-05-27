#include<iostream>
using namespace std;
class base1
{
    public:
    base1()
    {
        m_A=100;
    }
    int m_A;
};
class base2
{
    public:
    base2()
    {
        m_B=200;
    }
    int m_B;
};
class son : public base1,public base2
{
    public:
    son()
    {
        m_C=300;
        m_D=400;
    }
    int m_C;
    int m_D;
};
void test01()
{
    son s;
    cout<<"sieof(son)="<<sizeof(s)<<endl;//输出子类对象的大小
}