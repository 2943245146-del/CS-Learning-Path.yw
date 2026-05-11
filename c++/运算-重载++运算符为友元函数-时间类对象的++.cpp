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
    friend Time& operator++(Time& t);//前置++重载
    friend Time operator++(Time& t,int);//后置++重载
    void Show()
    {
        cout<<hour<<":"<<minute<<":"<<second<<endl;
    }
    private:
    int hour;
    int minute;
    int second;
};
Time& operator++(Time& t)//前置++重载
{
    t.second++;
    if(t.second==60)
    {
        t.second=0;
        t.minute++;
    }
    if(t.minute==60)
    {
        t.minute=0;
        t.hour++;
    }
    if(t.hour==24)
    {
        t.hour=0;
    }
    return t;
}
Time operator++(Time& t,int)//后置++重载
{    Time temp=t;
    t.second++;
    if(t.second==60)
    {
        t.second=0;
        t.minute++;
    }
    if(t.minute==60)
    {
        t.minute=0;     
        t.hour++;
    }
    if(t.hour==24)
    {
        t.hour=0;   
    }
    return temp;
}
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