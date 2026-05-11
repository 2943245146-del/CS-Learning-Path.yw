#include <iostream>
using namespace std;
class Time
{
    public:
    Time(int h=0,int m=0,int s=0)
    {
        hour=h;
        minute=m;
        second=s;
    }
    void Show()
    {
        cout<<hour<<":"<<minute<<":"<<second<<endl;
    }
    Time& operator++()
    {
        second++;
        if(second==60)
        {
            second=0;
            minute++;
        }
        else if(minute==60)
        {
            minute=0;
            hour++;
        }
        else if(hour==24)
        {
            hour=0;
        }
        return *this;
    }
    Time operator++(int)
    {
        Time temp=*this;
        second++;
        if(second==60)
        {
            second=0;
            minute++;
        }
        else if(minute==60)
        {
            minute=0;
            hour++;
        }
        else if(hour==24)
        {
            hour=0;
        }
        return temp;
    }
    private:
    int hour;
    int minute;
    int second;
};
int main()  
{  
   Time t1(10,25,52),t2,t3;//定义一个时间对象t1，带参数,t2、t3对象不带参数  
   t1.Show();  
   t2=++t1;//使用重载运算符++完成前置++  
   t1.Show();  
   t2.Show();  
   t3=t1++;//使用重载运算符++完成后置++  
   t3.Show();  
   t1.Show();  
   return 0;  
} 