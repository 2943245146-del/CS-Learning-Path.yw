//要求计算2点之间的距离。设平面中两点分别为p1(x1,y1)和p2(x2,y2)
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
};
int main( )  
{   Point p1(100,100),p2(200,300);  
    double a,b;  
    a=p1.GetX()-p2.GetX();  
    b=p1.GetY()-p2.GetY();        
    cout<<"两点间距离为:"<<sqrt(a*a+b*b)<<endl;  
    return 0;  
} 