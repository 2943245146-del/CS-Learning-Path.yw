#include <iostream>  
using namespace std;  
class Date{  
private:      
int year,month,day;//年月日  
bool IsLeapYear()//判断闰年  
{  
    return (year%4==0&&year%100!=0)||(year%400==0);  
}  
public:  
    Date& operator ++();        //前置单目运算符重载为成员函数  
    Date operator ++(int);    //后置单目运算符重载为成员函数  
    void ShowMe()//输出  
    {  
    cout<<year<<"-"<<month<<"-"<<day<<endl;  
    }  
    Date(int y=0,int m=0,int d=0)//带默认参数的构造函数（无参和有参合二为一）  
    {  
    year=y;  
    month=m;  
    day=d;  
    }  
};
Date& Date::operator ++()//前置单目运算符重载为成员函数  
{  
    day++;  
    if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31)  
    {  
        day=1;  
        month++;  
    }  
    else if((month==4||month==6||month==9||month==11)&&day>30)  
    {  
        day=1;  
        month++;  
    }  
    else if(month==2)  
    {  
        if(IsLeapYear()&&day>29)  
        {  
            day=1;  
            month++;  
        }  
        else if(!IsLeapYear()&&day>28)  
        {  
            day=1;  
            month++;  
        }  
    }  
    if(month>12)  
    {  
        month=1;  
        year++;  
    }   
    return *this;//返回当前对象的引用，方便链式调用（++(++x)） 
}
Date Date::operator ++(int)//后置单目运算符重载为成员函数  
{  
    Date temp=*this;//把当前对象的值保存到一个临时对象中，因为后置++需要返回原来的值，而前置++需要返回自增后的值，所以后置++需要一个临时对象来保存原来的值  
    day++;  
    if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31)  
    {  
        day=1;  
        month++;  
    }  
    else if((month==4||month==6||month==9||month==11)&&day>30)  
    {  
        day=1;  
        month++;  
    }  
    else if(month==2)  
    {  
        if(IsLeapYear()&&day>29)  
        {   
            day=1;  
            month++;  
        }  
        else if(!IsLeapYear()&&day>28)  
        {  
            day=1;  
            month++;  
        }  
    }  
    if(month>12)  
    {  
        month=1;  
        year++;  
    }  
    return temp;//返回临时对象，后置++需要返回原来的值，所以返回临时对象 
}
int main()  
{  
   int a,b,c;  
   cin>>a>>b>>c;  
   Date x(a,b,c),y;  
   x.ShowMe();
   y=x++;  
   x.ShowMe();     
   y.ShowMe();   
   y=++++x;   
   x.ShowMe();     
   y.ShowMe();     
   return 0;  
} 