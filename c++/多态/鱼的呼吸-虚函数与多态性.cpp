/*设animal类是fish类的基类，animal类的breathe()成员函数输出"animal breathe"，该函数在在fish类中被重写，输出"fish bubble"，要求根据main的预设代码，编程设计animal类和fish类。*/
#include<iostream>
using namespace std;
class animal
{
    public:
    virtual void breathe()//虚函数，使用virtual关键字修饰，使其成为虚函数，虚函数可以被子类重写，实现多态
    {
        cout<<"animal breathe"<<endl;
    }   
};
class fish:public animal
{
    public:
    virtual void breathe()//重写父类的虚函数，必须加上virtual关键
    {
        cout<<"fish bubble"<<endl;
    }
};
int main()  
{  
    fish fh;      
    animal &An=fh;  
    An.breathe();   
} 
/*
 	测试输入帮助，input (新窗口)	期待的输出帮助，expectedoutput (新窗口)	时间限制帮助，timelimit (新窗口)	内存限制帮助，memlimit (新窗口)	额外进程帮助，nproc (新窗口)
测试用例 1	以文本方式显示
↵
以文本方式显示
fish bubble↵*/