//时间类的成员函数Display需要用到日期类的私有数据成员输出日期，方法2是在日期类中将时间类声明为友元类，这样时间类的所有成员函数都是日期类的友元函数，当然时间类的Display函数也是日期类的友元函数
#include<iostream>
using namespace std;
class Date  
{  
private:
int month,day,year;
public:
Date(int m,int d,int y)
{
month=m;
day=d;
year=y;
}
friend class Time;//将Time类声明为Date类的友元类，使Time类能够访问Date类的私有成员
};
class Time
{
private:
int hour,minute,second;
public:
Time(int h,int m,int s)
{
hour=h;
minute=m;
second=s;
}
void Display(Date& d)//定义成员函数Display
{
cout<<d.year<<"/"<<d.month<<"/"<<d.day<<endl<<hour<<":"<<minute<<":"<<second<<endl;//直接访问Date类的私有成员year、month和day获取日期信息进行输出
}
};
int main()  
{  
    Time t1(10,13,56);//定义时间类对象  
    Date d1(12,25,2012);//定义日期类对象  
    t1.Display(d1);//调用友元成员函数  
    return 0;  
}