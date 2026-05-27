/*电表的主要功能是计量电能的消耗。已有电表类Ammeter，其数据成员包括当前度数reading、电费单价price，成员函数有构造函数、显示信息的print（）函数以及计电流量的setReading（）函数。
智能预付费的电表示常见的一种电表，必须在其中预存一定的金额后才能合闸供电。用电时，以便计量电能消耗一边从剩余值中扣减已用的金额，扣完则断电。要求从Ammeter类派生出智能电表类Smartmeter，该类新增数据成员有预付款prepaid、剩余款balance，新增成员函数有构造函数、存入预付款的函数setPrepaid()、计算剩余款的CalcCharge()函数、重写了显示信息的print()函数。
其中CalcCharge()函数在每耗电一度时被调用一次来计算剩余款。
编写程序测试智能电表的功能，已知电费单价每度电0.48元。*/
#include <iostream>  
using namespace std;  
class Ammeter  
{  
public:  
    Ammeter(double r = 0);  
    void print();  
    void setReading(double amount);//计电流量     
protected:  //保护成员，供子类访问
    double reading;      //电表度数  
    static double price; //电费单价,静态成员  
};  
double Ammeter::price = 0.48;  //静态成员类外初始化
Ammeter::Ammeter(double r)  
{  
    setReading(r);  
}  
void Ammeter::setReading(double amount)  
{  
    reading = (amount > 0 ? amount : 0); //确保读入的度数非负   
}  
void Ammeter::print()   
{  
    cout << "用电度数:" << reading << ",单价:" << price;  
} 
class Smartmeter : public Ammeter
{
public:
    Smartmeter(double r = 0, double p = 0, double b = 0) : Ammeter(r), prepaid(p), balance(b) {}//构造函数，初始化列表初始化父类Ammeter和成员prepaid和balance
    void setPrepaid(double rin);
    double CalcCharge();
    void print();
private:
    double prepaid;
    double balance;
};  
void Smartmeter::setPrepaid(double rin)
{
    prepaid = (rin > 0 ? rin : 0); //确保预付款非负
    balance = prepaid; //初始剩余款等于预付款
}
double Smartmeter::CalcCharge()
{
    balance -= price; //每耗电一度扣减电费单价
    return balance; //返回剩余款
}
void Smartmeter::print()
{
    Ammeter::print(); //调用父类Ammeter的print函数显示用电度数和单价
    cout << ",预付款:" << prepaid << ",剩余款:" << balance << endl; //显示预付款和剩余款
}
int main()  
{  
    Smartmeter meter; // 电表底度为0度  
    int val = 1;  
    double balance,x;  
    cin >> x;            // 输入预付电费，x不能小于0  
    meter.setPrepaid(x); // 预付电费  
    meter.print();      
    while (1)   
    {  
        meter.setReading(val++);      // 用电量增加1度  
        balance = meter.CalcCharge(); // 计费一次           
        meter.print();// 扣完就断电  
        if(balance<0)break;  
    }   
    return 0;  
} 
/* 	测试输入帮助，input (新窗口)	期待的输出帮助，expectedoutput (新窗口)	时间限制帮助，timelimit (新窗口)	内存限制帮助，memlimit (新窗口)	额外进程帮助，nproc (新窗口)
测试用例 1	以文本方式显示
1↵
以文本方式显示
用电度数:0,单价:0.48,预付款:1,剩余款:1↵
用电度数:1,单价:0.48,预付款:1,剩余款:0.52↵
用电度数:2,单价:0.48,预付款:1,剩余款:0.04↵
用电度数:3,单价*/