/*设计一个简单的0-100以内（数据合法性检查：超出这个范围要有异常处理，操作符不是加减乘除也有异常处理，另外被0除也要异常处理）的整数计算器，可以完成加、减、乘、除四种算术运算。要求异常处理通过捕获抛出的异常是不同对象类型来处理不同的异常。*/
#include<iostream>
using namespace std;
class Calculator
{
    public:
    void calculate()
    {        int a,b;
        char op;
        cin>>a;
        if(a<0||a>100)
        {         throw "操作数超出范围";
        }        cin>>op;
        cin>>b;
        if(b<0||b>100)      {            throw "操作数超出范围";
        }        if(op=='/')
        {            if(b==0)            {
                throw "不能被0除";    
            }
            cout<<a/b<<endl;
        }
        else if(op=='+')
        {
            cout<<a+b<<endl;
        }
        else if(op=='-')
        {
            cout<<a-b<<endl;
        }
        else if(op=='*')
        {
            cout<<a*b<<endl;
        }
        else
        {
            throw "操作符非法";
        }
    }
};
int main()
{    Calculator calculator;
    try
    {        calculator.calculate();
    }    catch(const char* msg)
    {        cout<<msg<<endl;
    }    return 0;
}