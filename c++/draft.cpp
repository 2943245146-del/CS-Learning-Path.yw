/*设计一个圆类（其父类是点类）。两个圆的圆心和半径从键盘输入，例如输入：0 0 3 5 6 2，表示第一个圆的圆心(0,0),半径3，第二个圆的圆心(5,6),半径2。要求判断两个圆间的位置关系。
8.10*/
#include<iostream>
#include<cmath>
using namespace std;
class Point//点类定义
{
protected:  
    double x,y;//点坐标
public:
    Point(double i,double j)//带参数值的构造函数
    {
        x=i;
        y=j;
    }
    void Show()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};
class Circle:public Point//圆类定义，继承自点类
{
private:
    double r;//圆半径
public:
    Circle(double x1,double y1,double x2,double y2,double radius):Point(x2,y2),r(radius)//有参构造函数，使用成员初始化列表初始化父类Point和成员r
    {
    }
    void Show()
    {
        cout<<"圆心=";
        Point::Show();//调用父类Point的Show函数显示圆心坐标
        cout<<"半径="<<r<<endl;
    }
};
int main()
{
    double x1,y1,x2,y2,r;
    cin>>x1>>y1>>x2>>y2>>r;//从键盘输入点坐标、圆心坐标和圆半径
    Circle c(x1,y1,x2,y2,r);//定义一个圆对象，带5个参数
    double distance=sqrt(pow(x2-x1,2)+pow(y2-y1,2));//计算点与圆心的距离，使用sqrt和pow函数
    cout<<"点("<<x1<<","<<y1<<")与圆[点("<<x2<<","<<y2<<"),"<<r<<"]的距离="<<distance;//输出点与圆心的距离
    if(distance<r)
        cout<<",位置关系:点在圆内"<<endl;
    else if(distance==r)
        cout<<",位置关系:点在圆上"<<endl;
    else
        cout<<",位置关系:点在圆外"<<endl;
    return 0;
}