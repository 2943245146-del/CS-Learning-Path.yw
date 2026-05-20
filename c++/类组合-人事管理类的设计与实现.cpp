#include <iostream>  
#include <string>  
using namespace std;  
class Date//日期类定义  
{  
private:  
    int year,month,day;  
public:  
    Date(int y=0,int m=0,int d=0)//带默认参数的构造函数，无参和有参合二为一  
    {  
        year=y;  
        month=m;  
        day=d;  
    }  
    void Show()  
    {  
        cout<<year<<"-"<<month<<"-"<<day<<endl;  
    }  
}; 
class Person//雇员类定义  
{  
private:  
    int id;//雇员编号
    string sex;//雇员性别
    Date birthday;//雇员出生日期，类对象
    string name;//雇员姓名
public:
    Person(int i,int s,int y,int m,int d,string n)//带参数的构造函数，参数类型为基本数据类型和类对象
    {        id=i;
        if(s==1)
            sex="male";
        else
            sex="female";
        birthday=Date(y,m,d);
        name=n;
    }
    void Show()
    {
        cout<<id<<","<<sex<<endl;
        birthday.Show();
        cout<<name<<endl;
    }
};
int main()  
{  
   Person x(1,0,1980,12,31,"wangming");//定义一个雇员对象，带参数  
   x.Show();//输出雇员信息,注意该Show函数中调用日期对象的Show函数  
   return 0;  
} 
/*输出
1,female↵
1980-12-31↵
wangming↵
*/