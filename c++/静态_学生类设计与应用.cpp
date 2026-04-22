//定义一个学生类，使用静态成员完成计算若干学生的平均年龄。
#include<iostream>
using namespace std;
class Student  
{  
private:
    string name;
    int age;
public:    static int Totalage;//定义静态成员变量Totalage，用于累加所有学生的年龄
    static int GetNum()//定义静态成员函数GetNum，用于获取学生的数量
    {
        return num;
    }
    Student(string n,int a)
    {        name=n;
        age=a;
        Totalage+=a;//在构造函数中将每个学生的年龄累加到Totalage中
        num++;//在构造函数中将学生数量加1
    }
    void Show()
    {        cout<<"姓名:"<<name<<",年龄:"<<age<<endl;
    }
private:    static int num;//定义静态成员变量num，用于统计学生的数量
};
int Student::Totalage=0;//初始化静态成员变量Totalage
int Student::num=0;//初始化静态成员变量num
int main()   
{   
    Student stu1("John",10), stu2("Peter",5),stu3("Liming",9);   
    stu1.Show();  
    stu2.Show();  
    stu3.Show();  
    cout <<"平均年龄:"<<Student::Totalage/Student::GetNum() << endl; //输出平均年龄   
} 