#include <iostream>
using namespace std;   
class Circle//圆类   
{   
private:   
         double  r;   
public:   
    Circle(double a=0.0)  
    { r = a; }       
    double getArea()//返回圆面积  
    {   
        return 3.1415926 * r * r;          
    }  
    double getPerimeter()//返回圆周长  
    {      
        return 2*3.1415926 * r;          
    } 
}; 
class Column
{
private:
    Circle c;//圆类对象
    double h;//圆柱的高
public:
    Column(double a=0.0,double b=0.0):c(a),h(b){}//构造函数，初始化列表初始化圆类对象
    double getCubarea()//返回圆柱的面积
    {
        return 2*c.getArea()+c.getPerimeter()*h;//圆柱的面积=2*底面积+侧面积=2*圆面积+圆周长*高
    }
    double getCubage()//返回圆柱的体积
    {
        return c.getArea()*h;//圆柱的体积=底面积*高=圆面积*高
    }
};
int main()   
{   
    Column column(12,10);      
    cout<<"圆柱的面积:"<<column.getCubarea()<< endl;   
    cout<<"圆柱的体积:"<<column.getCubage()<< endl;   
    return 0;  
}