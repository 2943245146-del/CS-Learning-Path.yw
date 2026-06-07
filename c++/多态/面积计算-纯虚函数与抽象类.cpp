/*利用多态编程创建一个图形(Shape)类,求三角形(Triangle)和圆(Circle)的面积。圆周率用3.1415926参与计算。要求补充三角形类和圆类的设计*/
#include <iostream>  
using namespace std;  
class Shape  
{  
public:  
    virtual float area() = 0;   // 将area定义成纯虚函数  
};
class Triangle : public Shape  
{  
private:
    float base;  
    float height;  
public:  
    Triangle(float b, float h) : base(b), height(h) {}  
    virtual float area()  
    {  
        return 0.5 * base * height;  
    }  
};
class Circle : public Shape  
{  
private:
    float radius;  
public:  
    Circle(float r) : radius(r) {}  
    virtual float area()  
    {  
        return 3.1415926 * radius * radius;  
    }  
};
int main()  
{  
    Shape *pShape;  
    Triangle tri(3,4);  
    cout<<tri.area()<<endl;  
    pShape = &tri;  
    cout<<pShape->area()<<endl;  
    Circle cir(5);  
    cout<<cir.area()<<endl;  
    pShape = &cir;  
    cout<<pShape->area()<<endl;  
    return 0;  
}
/* 	测试输入帮助，input (新窗口)	期待的输出帮助，expectedoutput (新窗口)	时间限制帮助，timelimit (新窗口)	内存限制帮助，memlimit (新窗口)	额外进程帮助，nproc (新窗口)
测试用例 1	以文本方式显示
↵
以文本方式显示
6↵
6↵
78.5398↵
78.5398↵*/