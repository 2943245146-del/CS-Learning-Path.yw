#include<iostream>
#include<string>
using namespace std;
class Myprint
{
    public:
    void operator()(string str)//重载函数调用运算符，仿函数
    {
        cout<<str<<endl;
    }
};
void test01()
{
    Myprint myprint;
    myprint("Hello World!");//调用重载的函数调用运算符
}
int main()
{
    test01();
    return 0;
}