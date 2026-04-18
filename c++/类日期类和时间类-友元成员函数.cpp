// 时间类的成员函数Display需要用到日期类的私有数据成员输出日期，方法1是将时间类的成员函数Display声明为日期类的友元函数。
#include <iostream>
using namespace std;
class Date; // 前向声明Date类
class Time {
private:
    int hour, minute, second;
public:
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
    void Display(Date& d); // 先声明成员函数
};
class Date {
private:
    int month, day, year;
public:
    Date(int m, int d, int y) : month(m), day(d), year(y) {}
    friend void Time::Display(Date& d); // 友元声明
};
void Time::Display(Date& d) {
    cout << d.year << "/" << d.month << "/" << d.day << endl
         << hour << ":" << minute << ":" << second << endl;
}
int main() {
    Time t1(10, 13, 56);
    Date d1(12, 25, 2012);
    t1.Display(d1);
    return 0;
}