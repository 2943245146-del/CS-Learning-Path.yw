#include<iostream>
using namespace std;
class person
{
    public:
    person(int age)
    {
        this->age=age;//this指针指向当前对象的地址，通过this指针来访问当前对象的成员变量
    }
    person& personAddage(person &p)
    {
        this->age+=p.age;//this指针指向当前对象的地址，通过this指针来访问当前对象的成员变量
        //this是指向p2的指针，而*this是p2对象本身
        return *this;//返回当前对象的引用
    }
    int age;
};
//1解决名称冲突问题，this指针指向当前对象的地址，通过this指针来访问当前对象的成员变量
void test()
{
    person p1(18);
    cout<<p1.age<<endl;
}
//2返回对象本身用*this
void test2()
{
    person p1(18);
    person p2(5);
    p2.personAddage(p1).personAddage(p1).personAddage(p1);//把p1的年龄加到p2的年龄上
    cout<<p2.age<<endl;
}
int main()
{
    //test();
    test2();
    return 0;
}