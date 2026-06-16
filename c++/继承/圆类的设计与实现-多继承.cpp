/*设有一个Point类，有数据成员x和y。另有一个Color类，有数据成员a。
要求从Point类和Color类公有派生出Circle类，增加了数据成员r，这3个类都定义了Show函数输出其数据信息。请补充Circle类的定义，并分析用例输出为什么是这样的运行结果。*/
#include <iostream>  
using namespace std;  
enum MyColor{BLACK, WHITE,RED,YELLOW,GREEN};  
class Point  
{protected:  
    double x,y;   
public:  
    Point(double a,double b)  
    {x=a;y=b;  
    cout<<"调用Point类带参构造函数"<<endl;  
    }  
    Point()  
    {x=0;y=0;  
    cout<<"调用Point类无参构造函数"<<endl;  
    }  
    void Show()  
    {   cout<<x<<","<<y;  }     
};  
class Color  
{  
protected:  
        MyColor a;  
public:   
    Color(MyColor b)   
    {a=b;  
     cout<<"调用Color类带参构造函数"<<endl;   
    }  
    Color()   
    {a=BLACK;  
     cout<<"调用Color类无参构造函数"<<endl;   
    }  
    Color(Color &r)   
    {a=r.a;  
     cout<<"调用Color类拷贝构造函数"<<endl;   
    }  
    void Show()  
    {  
        cout<<"颜色=";  
        switch (a)  
        {  
            case 0:cout<<"BLACK"<<endl;break;  
            case 1:cout<<"WHITE"<<endl;break;  
            case 2:cout<<"RED"<<endl;break;  
            case 3:cout<<"YELLOW"<<endl;break;  
            case 4:cout<<"GREEN"<<endl;break;  
            default:cout<<"QITA"<<endl;  
        }  
    }     
};
class Circle:public Point,public Color
{
private:
    int r;
public:
    Circle(int a,int b,int c,MyColor d):Point(a,b),Color(d),r(c){
    }
    void Show()
    {
        cout<<"半径="<<r<<endl;
        cout<<"圆心=(";
        Point::Show();
        cout<<")"<<endl;
        Color::Show();
    }
};
int main()  
{  
    Circle c1(100,100,10,RED);//定义圆对象  
    c1.Show();//调用成员函数        
    return 0;  
} 
/*调用Point类带参构造函数↵
调用Color类带参构造函数↵
半径=10↵
圆心=(100,100)↵
颜色=RED↵*/