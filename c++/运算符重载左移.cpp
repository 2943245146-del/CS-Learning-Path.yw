#include<iostream>
using namespace std;
class person
{
    public:
    friend ostream& operator<<(ostream& out,const person& p);//友元函数，重载左移运算符，参数类型为person对象的引用
    person(int a,int b)
    {
        m_A=a;
        m_B=b;
    }
    private:
    int m_A;
    int m_B;
};
//只能用全局函数重载左移运算符
ostream& operator<<(ostream& out,const person& p)//链式编程思想，返回cout对象的引用
{
    out<<"m_A="<<p.m_A<<" m_B="<<p.m_B;
    return out;
}
void test01()
{
    person p1(10,20);
    cout<<p1<<endl;//调用重载的左移运算符
}
int main()
{
    test01();
    return 0;
}