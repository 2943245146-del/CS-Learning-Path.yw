/*定义2个类：线段类和点类，线段类是点类的子类，点类是线段类的父类，二者是继承关系。线段类包括2个点。成员函数能显示该线段的起点坐标、终点坐标以及线段的长度。2个点坐标从键盘输入，线段长度通过公式计算。*/
#include <iostream>
#include <cmath>
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
        cout<<"Point类的有参构造函数被调用"<<endl;  
    }  
    Point()//无参构造函数  
    {  
        x=0;  
        y=0;  
        cout<<"Point类的无参构造函数被调用"<<endl;  
    }  
    void Show()  
    {  
        cout<<"("<<x<<","<<y<<")"<<endl;  
    }  
};  
class Line:public Point//线段类定义，继承自点类  
{
private:    
    double endx;
    double endy;
public:
    Line(double x1,double y1,double x2,double y2):Point(x1,y1),endx(x2),endy(y2)//有参构造函数，使用成员初始化列表初始化父类Point和成员endx和endy  
    {  
        cout<<"Line类的有参构造函数被调用"<<endl;  
    }  
    void Show()  
    {  
        cout<<"start=";  
        Point::Show();//调用父类Point的Show函数显示线段起点坐标
        cout<<"end=("<<endx<<","<<endy<<")"<<endl;
        double length=sqrt(pow(endx-x,2)+pow(endy-y,2));//计算线段长度，使用sqrt和pow函数
        cout<<"length="<<length<<endl;
    }
};
int main()  
{  
   double x1,y1,x2,y2;  
   cin>>x1>>y1>>x2>>y2;//从键盘输入2个点坐标息    
   Line xd(x1,y1,x2,y2);//定义1个线段对象，带4个参数    
   xd.Show();//输出线段信息,注意该Show函数中调用点对象的Show函数     
   return 0;  
} 
/*期待的输出帮助，expectedoutput (新窗口)	时间限制帮助，timelimit (新窗口)	内存限制帮助，memlimit (新窗口)	额外进程帮助，nproc (新窗口)
测试用例 1	以文本方式显示
3 3 -2 7↵
以文本方式显示
Point类的有参构造函数被调用↵
Line类的有参构造函数被调用↵
start=(3,3)↵
end=(-2,7)↵
length=6.40312↵*/