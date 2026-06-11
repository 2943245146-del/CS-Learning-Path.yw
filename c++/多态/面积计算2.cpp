/*圆类Circle有如下数据成员和成员函数：圆心坐标、半径、面积函数、输出函数(即输出圆心坐标和半径信息)、相应构造函数
矩形类Rect有如下数据成员和成员函数：左上角顶点、宽、高、面积函数、输出函数(即输出顶点坐标、宽和高信息)、相应构造函数
基于继承性思想，设计上述两个类的共同父类Shape，并基于父类实现上述两个类。
基于上述两个类，实现1个圆对象和1个矩形对象的面积总和计算并输出，输出这2个对象的信息。*/
#include <iostream>  
using namespace std;  
class Shape  
{  
protected:  
    double x,y;  
public:  
    Shape(double a=0.0,double b=0.0)  
    {x=a;y=b;}
    virtual double area()=0;
    virtual void Show()=0;
    virtual ~Shape()
    {  }
};
class Circle:public Shape  
{  
private:  
    double r;  
public:
    Circle(double a=0.0,double b=0.0,double c=0.0):Shape(a,b),r(c)  
    {  }  
    virtual double area()  
    {  return 3.1415926*r*r;  }  
    virtual void Show()  
    {  cout<<"圆心="<<x<<","<<y<<",半径="<<r<<endl;  }  
    virtual ~Circle()  
    {  }  
};
class Rect:public Shape  
{  
private:  
    double w,h;  
public:
    Rect(double a=0.0,double b=0.0,double c=0.0,double d=0.0):Shape(a,b),w(c),h(d)  
    {  }  
    virtual double area()  
    {  return w*h;  }  
    virtual void Show()  
    {  cout<<"左上角顶点="<<x<<","<<y<<",宽="<<w<<",高="<<h<<endl;  }  
    virtual ~Rect()  
    {  };  
};  
int main()  
{     
    double m,e,f;  
    cin>>m>>e>>f;  
    Circle c1(100,100,m);  
    Rect r1(50,50,e,f);   
    Shape &s1=c1,&s2=r1;  
    s1.Show();    
    s2.Show();  
    cout<<"面积和="<<s1.area()+s2.area()<<endl;    
    return 0;  
}  
/*测试输入帮助，input (新窗口)	期待的输出帮助，expectedoutput (新窗口)	时间限制帮助，timelimit (新窗口)	内存限制帮助，memlimit (新窗口)	额外进程帮助，nproc (新窗口)
测试用例 1	以文本方式显示
1.2 2.3 3.4↵
以文本方式显示
圆心=100,100,半径=1.2↵
左上角顶点=50,50,宽=2.3,高=3.4↵
面积和=12.3439↵
无限制	64M	0
*/