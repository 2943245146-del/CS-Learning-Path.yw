//要求定义友元函数实现2个复数对象的加法运算。
#include<iostream>
using namespace std;
class Complex  
{  
private:
    double real,imag;
public:
    Complex(double r=0,double i=0)
    {        real=r;
        imag=i;
    }
    void Show()
    {        cout<<"("<<real<<","<<imag<<")"<<endl;
    }
    friend Complex add(Complex& a,Complex& b);//将add函数声明为Complex类的友元函数，使其能够访问Complex类的私有成员
};
Complex add(Complex& a,Complex& b)//定义add函数
{    Complex c;
    c.real=a.real+b.real;//直接访问Complex类的私有成员real和imag获取两个复数的实部和虚部进行加法运算
    c.imag=a.imag+b.imag;
    return c;
};
int main()     //主函数  
{  
    Complex z1(1.5,2.8),z2(-2.3,3.4),z3;  //声明复数类的对象  
    z3=add(z1,z2);//友元函数调用  
    cout<<"z3=";  
    z3.Show();  
    return 0;  
} 