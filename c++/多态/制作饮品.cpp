#include<iostream>
using namespace std;
class AbstractDrinking
{
    public:
    //煮水
    virtual void boiling()=0;
    //泡茶
    virtual void brewing()=0;
    //倒茶
    virtual void pouring()=0;
    //辅料 
    virtual void addSomething()=0;
    void makeDrink()//制作饮品的流程
    {
        boiling();
        brewing();
        pouring();
        addSomething();
    }
};
class coffee:public AbstractDrinking
{
    public:
    virtual void boiling()
    {
        cout<<"煮水"<<endl;
    }
    virtual void brewing()
    {
        cout<<"泡咖啡"<<endl;
    }
    virtual void pouring()
    {
        cout<<"倒咖啡"<<endl;
    }
    virtual void addSomething()
    {
        cout<<"加糖和牛奶"<<endl;
    }
};
class tea:public AbstractDrinking
{
    public:
    virtual void boiling()
    {
        cout<<"煮水"<<endl;
    }
    virtual void brewing()
    {
        cout<<"泡茶"<<endl;
    }
    virtual void pouring()
    {
        cout<<"倒茶"<<endl;
    }
    virtual void addSomething()
    {
        cout<<"加柠檬"<<endl;
    }
};
void Dowork(AbstractDrinking *abs)//父类指针指向子类对象，发生了多态
{   abs->makeDrink();//调用的是子类的makeDrink函数
    delete abs;
}
void test01()
{
    Dowork(new coffee);
    Dowork(new tea);
}
int main()
{  
    test01();
    return 0;
}