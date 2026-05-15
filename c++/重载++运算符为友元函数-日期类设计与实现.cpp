#include <iostream>
using namespace std;
class A{
    int a,b;
    public:
    A()
    {
        a=0;
        b=0;
        cout<<"调用无参数的构造函数!"<<endl;
    }
    A(int x, int y)
    {
        a=x;
        b=y;
        cout<<"调用一般构造函数!"<<endl;
    }
    void print()
    {
        cout<<"对象a的值:"<<a<<",对象b的值:"<<b<<endl;
    }
};
int main()
{
    A m,n(6,8);
    m.print();
    n.print();
    return 0;
}