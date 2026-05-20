#include <iostream>  
#include <string>  
using namespace std;  
class Square//正方形类  
{  
private:  
    double x;//边长  
public:  
    Square(double i=0)//带默认参数值的构造函数  
    {   x=i;          
    }  
    double getx()  
    {  
        return x;  
    }      
};  
class Circle//圆类  
{  
private:  
    double r;//半径  
public:  
    Circle(double i=0)//带默认参数值的构造函数  
    {   r=i;          
    }  
    double getr()  
    {  
        return r;  
    }      
};
class Coin//钱币类  
{  
private:
    double diameter;//直径  
    double weight;//重量  
    string text;//钱币文字  
    string material;//材质  
    Square square;//方孔类对象  
    Circle circle;//圆类对象  
public:
    Coin(double x,double r,double w,string t,string m)//带参数的构造函数
    {        diameter=2*r;
        weight=w;   
        text=t;
        material=m;
        square=Square(x);
        circle=Circle(r);
    }
    Coin(Square s,Circle c,double w,string t,string m)//带参数的构造函数
    {        diameter=2*c.getr();
        weight=w;   
        text=t;
        material=m;
        square=s;
        circle=c;
    }
    void Show() 
    {  
        cout<<"钱币文字="<<text<<endl;  
        cout<<"材质="<<material<<endl;  
        cout<<"直径="<<diameter<<"厘米"<<endl;  
        cout<<"方孔边长="<<square.getx()<<"厘米"<<endl;  
        cout<<"重量="<<weight<<"克"<<endl;  
    }
};
int main()  
{  
    Square x(0.2);  
    Circle y(1.25);  
    Coin m(0.3,1.3,5.13,"开元通宝","银"),n(x,y,3.5,"五铢","铜");  
    m.Show();  
    n.Show();  
    return 0;  
}
/*输出
钱币文字=开元通宝↵
材质=银↵
直径=2.6厘米↵
方孔边长=0.3厘米↵
重量=5.13克↵
钱币文字=五铢↵
材质=铜↵
直径=2.5厘米↵
方孔边长=0.2厘米↵
重量=3.5克↵*/