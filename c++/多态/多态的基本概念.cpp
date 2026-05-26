#include<iostream>
using namespace std;
class Animal
{
    public:
    virtual void speack()//虚函数，使用virtual关键字修饰，使其成为虚函数，能够实现动态联编
    {
        cout<<"动物在说话"<<endl;
    }
};
class Cat:public Animal
{
    public:
    void speack()
    {
        cout<<"猫在说话"<<endl;
    }
};
class Dog:public Animal
{
    public:
    void speack()
    {
        cout<<"狗在说话"<<endl;
    }
};
//执行说话函数
//地址早绑定在编译阶段就能确定函数的地址，编译器会根据传入的参数类型来确定调用哪个函数，这就是静态联编
//如果想要猫说话，需要在运行阶段进行绑定，地址晚绑定在运行阶段才能确定函数的地址，编译器会根据传入的参数类型来确定调用哪个函数，这就是动态联编
//动态多态满足条件：1.必须有继承关系；2.子类重写父类的虚函数；3.父类指针或引用指向子类对象
void doSpeak(Animal &animal)//父类引用指向子类对象，发生了多态
{    animal.speack();//调用的是子类的speack函数

}
int main()
{    Cat cat;
    Dog dog;
    doSpeak(cat); 
    doSpeak(dog);
    return 0;
}