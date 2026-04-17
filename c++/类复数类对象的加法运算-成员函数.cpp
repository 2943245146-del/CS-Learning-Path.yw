//要求定义成员函数实现2个复数对象的加法运算
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
    Complex add(Complex& b)//定义成员函数add
    {
        Complex c;
        c.real=real+b.real;//直接访问Complex类的私有成员real和imag获取两个复数的实部和虚部进行加法运算
        c.imag=imag+b.imag;
        return c;
    }
};
int main()     //主函数  
{  
    Complex z1(1.5,2.8),z2(-2.3,3.4),z3;  //声明复数类的对象  
    z3=z1.add(z2);//成员函数调用  
    cout<<"z3=";  
    z3.Show();  
    return 0;  
} 