/*设计一个简单的0-100以内（数据合法性检查：超出这个范围要有提示，另外被0除也要有提示，要求用if来实现）的整数计算器，可以完成加、减、乘、除四种算术运算。要求使用面向对象方法实现。*/
#include<iostream>
using namespace std;
class Calculator
{
    public:
    void calculate()
    {
        int a,b;
        char op;
        cin>>a;
        if(a<0||a>100)
        {
            cout<<"操作数超出范围"<<endl;
            return;
        }
        cin>>op;
        cin>>b;
        if(b<0||b>100)
        {
            cout<<"操作数超出范围"<<endl;
            return;
        }
        if(op=='/')
        {
            if(b==0)            {
                cout<<"不能被0除"<<endl;    
                return;
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
            cout<<"操作符非法"<<endl;
            return;
        }
    }
};
int main()
{    Calculator calculator;
    calculator.calculate();
    return 0;
}
//输入：a=10，op='/'，b=0
//输出：除数不能为0！
//输入：a=150，op='+'，b=20
//输出：输入的整数不合法，请输入0-100之间的整数！