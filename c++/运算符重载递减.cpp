#include<iostream>
using namespace std;
class MyInteger
{
    public:
    friend ostream& operator<<(ostream& out,const MyInteger& p);//友元函数，重载左移运算符，参数类型为MyInteger对象的引用
    MyInteger()
    {
        m_Num=0;
    }
    MyInteger& operator--()//前置--重载
    {
        m_Num--;
        return *this;
    }
    MyInteger operator--(int)//后置--重载
    {
        MyInteger temp=*this;//把当前对象的值保存到一个临时对象中
        m_Num--;//把当前对象的值减1
        return temp;//返回临时对象
    }
    private:
    int m_Num;
};
ostream& operator<<(ostream& out,const MyInteger& p)//重载左移运算符，参数类型为MyInteger对象的引用
{
    out<<p.m_Num;
    return out;
}
void test01()
{
    MyInteger p1;
    cout<<--p1<<endl;
}
void test02()
{
    MyInteger p1;
    cout<<p1--<<endl;
    cout<<p1<<endl;
}
int main()
{
    test02();
    return 0;
}