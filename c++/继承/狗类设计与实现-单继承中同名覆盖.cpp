/*设有一个Mammal类，有数据成员itsAge和itsWeight，公有派生出Dog类，增加了数据成员itsColor，这2个类都定义了Speak函数输出其语言。请补充Dog类的定义，并分析用例输出为什么是这样的运行结果。*/
#include <iostream>  
using namespace std;  //考察单继承中同名覆盖，单继承中同名覆盖是指子类中定义了一个与父类中同名的成员函数，这个函数会覆盖父类中的同名函数，当通过子类对象调用这个函数时，调用的是子类中的版本，而不是父类中的版本。单继承中同名覆盖的运行结果是这样的，因为当我们创建一个Dog对象并调用Speak函数时，程序会优先调用Dog类中的Speak函数，而不是Mammal类中的Speak函数，所以输出的是Dog语言，而不是Mammal语言。
enum MyColor{BLACK, WHITE};//枚举类型   
class Mammal  
{  
public:  
    Mammal(int age, int weight):itsAge(age),itsWeight(weight){}  
    int GetAge(){return itsAge;}  
    int GetWeight(){return itsWeight;}  
    void Speak(){cout<<"Mammal language!"<<endl;}  
protected:  
    int itsAge;     //年龄     
    int itsWeight;  //体重  
};
class Dog:public Mammal  
{  
public:  
    Dog(int age, int weight, MyColor color):Mammal(age, weight),itsColor(color){}  
    MyColor GetColor(){return itsColor;}  
    void Speak(){cout<<"Dog language!"<<endl;}  
private:  
    MyColor itsColor;  //颜色  
};
int main()  
{  
    Dog dog(25,50,WHITE);//最后一个参数是枚举类型   
    cout<<"Dog age = "<<dog.GetAge()<<endl;  
    cout<<"Dog weight = "<<dog.GetWeight()<<endl;   
    cout<<"Dog color = "<<dog.GetColor()<<endl;     
    dog.Speak();  
    return 0;  
};
/*期待的输出帮助，expectedoutput (新窗口)	时间限制帮助，timelimit (新窗口)	内存限制帮助，memlimit (新窗口)	额外进程帮助，nproc (新窗口)
测试用例 1	以文本方式显示
↵
以文本方式显示
Dog age = 25↵
Dog weight = 50↵
Dog color = 1↵
Dog language!↵*/