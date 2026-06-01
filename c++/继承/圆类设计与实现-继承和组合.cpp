/*设有一个Point类，有数据成员x和y。另有一个Color类，有数据成员a。
要求从Point类公有派生出Circle类，增加了数据成员r和颜色对象p，这3个类都定义了Show函数输出其数据信息。请补充Circle类的定义，并分析用例输出为什么是这样的运行结果。*/
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
    {   cout<<x<<","<<y;  }    //输出的圆心坐标带括号 
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
class Circle:public Point  
{  
private:    double r;  
    Color p;  
public:    Circle(double a,double b,double c,Color &d):Point(a,b),r(c),p(d){}  
    void Show()  
    {
        cout<<"半径="<<r<<endl;
        cout<<"圆心=(";
         Point::Show();
         cout<<")"<<endl;
         p.Show();
    }  
};
int main()  
{  
    Color b(RED);  
    Circle c1(100.0,100.0,10.0,b);//定义圆对象  
    c1.Show();//调用成员函数        
    return 0;  
}  
/*
 	测试输入帮助，input (新窗口)	期待的输出帮助，expectedoutput (新窗口)	时间限制帮助，timelimit (新窗口)	内存限制帮助，memlimit (新窗口)	额外进程帮助，nproc (新窗口)
测试用例 1	以文本方式显示
↵
以文本方式显示
调用Color类带参构造函数↵
调用Point类带参构造函数↵
调用Color类拷贝构造函数↵
半径=10↵
圆心=(100,100)↵
颜色=RED↵*/