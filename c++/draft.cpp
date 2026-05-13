#include <iostream>  
using namespace std;  
class boat  
{  
    public:  
    boat(int w)    {  
        weight=w;  
    }  
    void show()  
    {  
        cout<<"boat重"<<weight<<endl;  
    }  
    int weight;  
};  
class car  
{    public:  
    car(int w)  
    {        weight=w;  
    }  
    void show()  
    {        cout<<"car重"<<weight<<endl;  
    }     
    int weight;  
};  
//重载+运算符，参数类型为boat对象的引用，返回值类型为int类型
int operator+(const boat& b1,const boat& b2)
{    return b1.weight+b2.weight;
}
//重载+运算符，参数类型为boat对象和car对象的引用，返回值类型为int类型
int operator+(const boat& b,const car& c)
{    return b.weight+c.weight;
}
int main()  
{  
    boat b(4),b2(6),b3(8);  
    car c(5);  
    b.show();  
    c.show();  
    cout<<"总重"<<b+b2+c+b3<<endl;  
    return 0;  
} 