/*用+运算符实现复数类对象的加法运算，用重载+运算符为友元函数*/
#include<iostream>
using namespace std;
class domplex
{
    public:
    domplex(double r=0,double i=0)
    {
        real=r; 
        imag=i;
    }
    void Show()
    {
        cout<<"("<<real<<","<<imag<<")"<<endl;  
    }
    friend domplex operator+(const domplex& c1,const domplex& c2);//重载+运算符，参数类型为domplex对象的引用
    private:
    double real;
    double imag;
};
domplex operator+(const domplex& c1,const domplex& c2)//重载+运算符，参数类型为domplex对象的引用
{
    domplex temp;
    temp.real=c1.real+c2.real;
    temp.imag=c1.imag+c2.imag;
    return temp;
}
int main()     //主函数  
{  
    domplex z1(1.5,2.8),z2(-2.3,3.4),z3;  //声明复数类的对象  
    z3=z1+z2;//+运算符被重载  
    cout<<"z3=";  
    z3.Show();  
    return 0;  
} 
//期待输出:z3=(-0.8,6.2)