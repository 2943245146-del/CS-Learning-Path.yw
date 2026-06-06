#include<iostream>
using namespace std;
class Base
{
    public:
    //只要有一个纯虚函数，整个类就成为抽象类，抽象类无法实例化对象
    //抽象类的子类必须重写父类的纯虚函数，否则子类也成为抽象类，无法实例化对象
    virtual void func()=0;//纯虚函数，使用virtual关键字修饰，并且赋值为0，使其成为纯虚函数

};
class son:public Base
{
    public:
    virtual void func()//重写父类的纯虚函数，必须加上virtual关键字修饰，否则无法实现多态
    {
        cout<<"func函数被调用了"<<endl;
    }
};
void test01()
{   //抽象类无法实例化对象
    //Base b;//错误，抽象类无法实例化对象
    //son s;//正确，子类可以实例化对象
    //s.func();
    Base *b=new son;//父类指针指向子类对象，发生了多态
    b->func();//调用的是子类的func函数
    delete b;
}
int main()
{    test01();
    return 0;
}