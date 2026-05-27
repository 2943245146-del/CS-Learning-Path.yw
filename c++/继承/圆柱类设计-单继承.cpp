#include <iostream>   
using namespace std;   
class Circle//圆类   
{   
protected:   
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
class Column : public Circle
{
private:
    double h;//圆柱的高
public:
    Column(double a=0.0,double b=0.0):Circle(a),h(b){}//构造函数，初始化列表初始化父类Circle和成员h
    double getCubarea()//返回圆柱的表面积
    {
        return 2 * getArea() + getPerimeter() * h;
    }
    double getCubage()//返回圆柱的体积
    {
        return getArea() * h;
    }
};
int main()   
{   
    Column column(12,10);      
    cout<<"圆柱的面积:"<<column.getCubarea()<< endl;   
    cout<<"圆柱的体积:"<<column.getCubage()<< endl;   
    return 0;  
}  