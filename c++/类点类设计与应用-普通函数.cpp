//定义一个普通函数（double Distance( Point& a, Point& b);用于计算两点间的距离。
#include<iostream>
#include<cmath>
using namespace std;
class Point  
{  
private:
    double x,y;
public:
    Point(double a,double b)
    {        x=a;
        y=b;
    }
    double GetX()
    {        return x;
    }
    double GetY()
    {
        return y;
    }
};
double Distance(Point& a, Point& b)//定义一个普通函数（double Distance( Point& a, Point& b);用于计算两点间的距离。
{
    double dx=a.GetX()-b.GetX();
    double dy=a.GetY()-b.GetY();
    return sqrt(dx*dx+dy*dy);
}
int main( )  
{   Point p1(100,100),p2(200,300);  
    cout<<"两点间距离为:"<<Distance(p1, p2)<<endl;//普通函数被调用;  
    return 0;  
}  