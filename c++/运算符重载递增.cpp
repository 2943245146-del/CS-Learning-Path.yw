#include<iostream>
using namespace std;
class MyInteger
{
    friend ostream& operator<<(ostream& out,const MyInteger& p);//友元函数，重载左移运算符，参数类型为MyInteger对象的引用
    public:
    MyInteger()
    {
        m_Num=0;
    }
    //返回引用是为了一直对一个数据进行操作，而不是每次都返回一个新的对象
    MyInteger& operator++()//前置++重载
    {
        m_Num++;
        return *this;
    }
    //后置++重载
    //不返回引用因为temp用完销毁，返回一个值
    MyInteger operator++(int)//int 表示占位参数，区分前置++和后置++
    {
        MyInteger temp=*this;//把当前对象的值保存到一个临时对象中
        m_Num++;//把当前对象的值加1
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
void test02()
{
    MyInteger p1;
    cout<<p1++<<endl;//调用后置++重载
    cout<<p1<<endl;//调用重载的左移运算符
}
int main()
{
    MyInteger p1;
    cout<<++p1<<endl;//调用重载的左移运算符
    test02();
    return 0;
}