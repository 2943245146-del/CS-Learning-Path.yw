#include <iostream>
using namespace std;
class a
{
    double t1,r;
    public:
    a(double t1,double r)
    {
        this->t1=t1;
        this->r=r;
    }
    friend double count(a &a)
    {
        a.t1+=a.r*a.t1;
        return a.t1;
    }
};
int main()
{
    a a1(160.6,0.64),a2(76.8,0.6);
    cout<<count(a1)<<endl;
    cout<<count(a2)<<endl;
    return 0;
}