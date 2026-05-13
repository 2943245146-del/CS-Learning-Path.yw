#include <iostream>
using namespace std;
class Date
{
    public:
    Date(int y=0,int m=0,int d=0)
    {
        year=y;
        month=m;
        day=d;
    }   
    void Show()
    {
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }
    friend istream& operator>>(istream& in,Date& d);//重载输入运算符，参数类型为Date对象的引用
    private:
    int year;   
    int month;
    int day;
};
istream& operator>>(istream& in,Date& d)//重载输入运算符，参数类型为Date对象的引用
{
    in>>d.year>>d.month>>d.day;
    return in;
}
int main()  
{  
    Date d1;  
    cin>>d1;//输入对象  
    d1.Show();  
    return 0;  
}  