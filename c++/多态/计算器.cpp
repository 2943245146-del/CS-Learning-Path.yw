#include<iostream>
using namespace std;
class AbstractCalculator
{
    public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};
class AddCalculator:public AbstractCalculator
{
    public:
    virtual int getResult()
    {
        return m_Num1+m_Num2;
    }
};
class SubCalculator:public AbstractCalculator
{
    public:
    virtual int getResult()
    {
        return m_Num1-m_Num2;
    }
};
class MulCalculator:public AbstractCalculator
{
    public:
    virtual int getResult()
    {
        return m_Num1*m_Num2;
    }
};
class DivCalculator:public AbstractCalculator
{
    public:
    virtual int getResult()
    {
        if(m_Num2==0)
        {   cout<<"除数不能为0"<<endl;
            return 0;
        }
        return m_Num1/m_Num2;
    }
};
void test01()
{  //多态的使用条件
    //父类指针或引用指向子类对象
    AbstractCalculator *abc=new AddCalculator;//父类指针指向子类对象
    abc->m_Num1=10;
    abc->m_Num2=10;
    cout<<"加法结果为："<<abc->getResult()<<endl;
    delete abc;
    abc=new SubCalculator;
    abc->m_Num1=10;
    abc->m_Num2=10;
    cout<<"减法结果为："<<abc->getResult()<<endl;   
    delete abc;
    abc=new MulCalculator;
    abc->m_Num1=10;
    abc->m_Num2=10;
    cout<<"乘法结果为："<<abc->getResult()<<endl;
    delete abc;
    abc=new DivCalculator;
    abc->m_Num1=10;
    abc->m_Num2=10;
    cout<<"除法结果为："<<abc->getResult()<<endl;
    delete abc;
}
int main()
{   test01();
    return 0;
}