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
    friend Date operator ++(Date &x);        //前置单目运算符重载为友元函数  
    friend Date operator ++(Date &x,int);    //后置单目运算符重载为友元函数  
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
Date operator ++(Date &x)//前置单目运算符重载为友元函数  
{  
    x.day++;  
    if((x.month==1||x.month==3||x.month==5||x.month==7||x.month==8||x.month==10||x.month==12)&&x.day>31)  
    {  
        x.day=1;  
        x.month++;  
    }  
    else if((x.month==4||x.month==6||x.month==9||x.month==11)&&x.day>30)  
    {  
        x.day=1;  
        x.month++;  
    }  
    else if(x.month==2)  
    {  
        if(x.IsLeapYear()&&x.day>29)  
        {  
            x.day=1;  
            x.month++;  
        }  
        else if(!x.IsLeapYear()&&x.day>28)  
        {  
            x.day=1;  
            x.month++;  
        }  
    }  
    if(x.month>12)  
    {  
        x.month=1;  
        x.year++;  
    }   
    return x;//返回当前对象，方便链式调用（++(++x)） 
}
Date operator ++(Date &x,int)//后置单目运算符重载为友元函数  
{   
    Date temp=x;//把当前对象的值保存到一个临时对象中，因为后置++需要返回原来的值，而前置++需要返回自增后的值，所以后置++需要一个临时对象来保存原来的值  
    x.day++;
    if((x.month==1||x.month==3||x.month==5||x.month==7||x.month==8||x.month==10||x.month==12)&&x.day>31)  
    {  
        x.day=1;  
        x.month++;  
    }  
    else if((x.month==4||x.month==6||x.month==9||x.month==11)&&x.day>30)  
    {  
        x.day=1;  
        x.month++;  
    }  
    else if(x.month==2)  
    {  
        if(x.IsLeapYear()&&x.day>29)  
        {  
            x.day=1;  
            x.month++;  
        }  
        else if(!x.IsLeapYear()&&x.day>28)  
        {  
            x.day=1;  
            x.month++;  
        }  
    }  
    if(x.month>12)  
    {  
        x.month=1;  
        x.year++;  
    }   
    return temp;//返回临时对象
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
   y=++x;   
   x.ShowMe();     
   y.ShowMe();     
   return 0;  
} 
/*
测试用例 1	
2017 12 31
2017-12-31
2018-1-1
2017-12-31
2018-1-2
2018-1-2*/