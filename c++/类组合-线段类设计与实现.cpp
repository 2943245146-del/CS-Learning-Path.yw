/*要求在Point类基础上采用类组合的思想，设计一个线段类，如图所示，线段类包括2个点类对象，成员函数能显示该线段的起点坐标、终点坐标以及线段的长度。2个点坐标从键盘输入，线段长度通过公式计算。*/
/*输出：Point类的带参数构造函数被调用↵
Point类的带参数构造函数被调用↵
Point类的复制构造函数被调用↵
Point类的复制构造函数被调用↵
Line类的有参构造函数1被调用↵
start=(100,100)↵
end=(200,300)↵
length=223.607↵
Point类的带参数构造函数被调用↵
Point类的带参数构造函数被调用↵
Line类的有参构造函数2被调用↵
start=(100,100)↵
end=(200,300)↵
length=223.607↵*/
#include <iostream>  
#include <cmath>  
using namespace std;  
class Point//点类定义  
{  
private:  
    double x,y;//点坐标  
public:  
    Point(double i,double j)//带参数的构造函数  
    {  
        x=i;  
        y=j;  
        cout<<"Point类的带参数构造函数被调用"<<endl;  
    }  
    Point()//无参构造函数  
    {  
        x=0;  
        y=0;  
        cout<<"Point类的无参构造函数被调用"<<endl;  
    }  
    Point(Point &p)//复制构造函数  
    {  
        x=p.x;  
        y=p.y;  
        cout<<"Point类的复制构造函数被调用"<<endl;  
    }  
    double getx()  
    {  
        return x;  
    }  
    double gety()  
    {  
        return y;  
    }  
    void Show()  
    {  
        cout<<"("<<x<<","<<y<<")"<<endl;  
    }  
}; 
class Line//线段类定义  
{  
private:  
    Point start;//线段起点  
    Point end;//线段终点  
public:  
    Line(Point &s,Point &e):start(s),end(e)//有参构造函数1，使用成员初始化列表初始化start和end  
    {  
        cout<<"Line类的有参构造函数1被调用"<<endl;  
    }  
    Line(double x1,double y1,double x2,double y2):start(x1,y1),end(x2,y2)//有参构造函数2，使用成员初始化列表初始化start和end  
    {  
        cout<<"Line类的有参构造函数2被调用"<<endl;  
    }  
    void Show()  
    {  
        cout<<"start=";  
        start.Show();  
        cout<<"end=";  
        end.Show();  
        double length=sqrt(pow(end.getx()-start.getx(),2)+pow(end.gety()-start.gety(),2));//计算线段长度  
        cout<<"length="<<length<<endl;  
    }  
};
int main()  
{  
   Point p1(100,100),p2(200,300);  
   Line xd1(p1,p2);  
   xd1.Show();     
   Line xd2(100,100,200,300);  
   xd2.Show();  
   return 0;  
} 