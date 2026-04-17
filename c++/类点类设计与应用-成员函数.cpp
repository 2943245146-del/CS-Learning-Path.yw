//定义一个成员函数（double Distance( Point& b);用于计算两点间的距离。
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
    {        return y;
    }
    double Distance(Point& b)//定义成员函数Distance
    {
        double dx=x-b.GetX();
        double dy=y-b.GetY();
        return sqrt(dx*dx+dy*dy);
    }
};
int main( )  
{   Point p1(100,100),p2(200,300);  
    cout<<"两点间距离为:"<<p1.Distance(p2)<<endl;//成员函数被调用;  
    return 0;  
} 