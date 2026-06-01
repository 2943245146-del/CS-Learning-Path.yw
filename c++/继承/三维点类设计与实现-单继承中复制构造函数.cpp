/*设Point类数据有x,y点坐标，三维点类TDpoint是Point类的子类，新增z点坐标，Distance（TDPoint &p)函数计算当前点坐标与给定点的距离。注意各种构造函数用法。*/
#include <iostream>  
#include <cmath>  
using namespace std;  
class Point//点类定义  
{  
protected:  
    double x,y;//点坐标  
public:  
    Point(double i,double j)//带参数值的构造函数  
    {   x=i;y=j;  
        cout<<"Point类的有参构造函数被调用"<<endl;  
    }  
    Point()//无参构造函数  
    {   x=0;y=0;  
        cout<<"Point类的无参构造函数被调用"<<endl;  
    }  
    Point(Point &r)//复制构造函数  
    {   x=r.x;  y=r.y;  
        cout<<"Point类的复制构造函数被调用"<<endl;  
    }  
    void Show()  
    {   cout<<"("<<x<<","<<y<<")"<<endl;}  
};
class TDpoint:public Point//三维点类定义，继承自点类  
{
private:    double z;//z点坐标  
public:    TDpoint(double i,double j,double k):Point(i,j),z(k)//有参构造函数，使用成员初始化列表初始化父类Point和成员z  
    {
        cout<<"TDpoint类的有参构造函数被调用"<<endl;
    }
    TDpoint():Point(),z(0)//无参构造函数，使用成员初始化列表初始化父类Point和成员z  
    {
        cout<<"TDpoint类的无参构造函数被调用"<<endl;
    }
    TDpoint(TDpoint &r):Point(r),z(r.z)//复制构造函数，使用成员初始化列表调用父类Point的复制构造函数和成员z的复制构造函数  
    {
        cout<<"TDpoint类的复制构造函数被调用"<<endl;
    }
    double Distance(TDpoint &p)//计算当前点坐标与给定点的距离  
    {
        return sqrt(pow(x-p.x,2)+pow(y-p.y,2)+pow(z-p.z,2));
    }
};
int main()  
{  
    TDpoint p1,p2(30,20,10),p3(p2);  
    cout<<p1.Distance(p2)<<endl;  
    cout<<p1.Distance(p3)<<endl;  
return 0;  
};
/*
 	测试输入帮助，input (新窗口)	期待的输出帮助，expectedoutput (新窗口)	时间限制帮助，timelimit (新窗口)	内存限制帮助，memlimit (新窗口)	额外进程帮助，nproc (新窗口)
测试用例 1	以文本方式显示
↵
以文本方式显示
Point类的无参构造函数被调用↵
TDpoint类的无参构造函数被调用↵
Point类的有参构造函数被调用↵
TDpoint类的有参构造函数被调用↵
Point类的复制构造函数被调用↵
TDpoint类的复制构造函数被调用↵
37.4166↵
37.4166↵*/