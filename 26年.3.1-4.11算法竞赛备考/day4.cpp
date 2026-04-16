// #include<iostream>
// #include<algorithm>
// using namespace std;
// //顺序表的动态实现
// int main()
// {
//     int* a;
//     int capacity;
//     int size;
//     a=new int[4];
//     capacity=4;
//     int* t=new int[capacity*2];
//     delete[] a;
//     a=t;
//     capacity*=2;
//     return 0;
// }
// void shanchubiaotou()
// {
//     for(int i=2;i<n;i++)
//     {
//         arr[i]=arr[i+1];
//     }
// }
// void push_back(int a[],int &size,int x)
// {
//     a[size]=x;
//     size++;
// }
#include<iostream>
using namespace std;
const int N=10;
void print(vector<int>& a)//利用size遍历
{
    for(int i=0;i<a.size();i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
}
void print2(vector<int>& a)//利用迭代器遍历
{
    for(auto i=a.begin();i!=a.end();i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}
void print3(vector<int>& a)//利用范围for循环遍历
{
    for(auto i:a)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    //创建vector对象，默认构造函数创建一个空的vector
    vector<int> a1;//创建了一个空的可变长数组，类型都是int
    vector<int> a2(N);//创建一个大小为10的可变长数组,默认值为0；
    vector<int> a3(N,1);//创建一个大小为10的可变长数组，初始值为1；
    vector<int> a4={1,2,3,4,5};//创建一个可变长数组，初始值为1,2,3,4,5；
    vector<string> a5={"hello","world"};//创建一个可变长数组，初始值为"hello","world";
    vector<vector<int>> a6={{1,2,3},{4,5,6}};//创建一个二维可变长数组，初始值为{{1,2,3},{4,5,6}};
    vector<int> a7[N];//创建一个vector数组,与a2(N)区分；
    // print(a2);
    // if(a1.empty())//判断a1是否为空
    // {
    //     cout << "a1 is empty" << endl;
    // }
    // else{
    //     cout << "a1 is not empty" << endl;
    // }
    // print2(a2);
    // print2(a3);
    for(int i=0;i<5;i++)//尾插与尾删
    {
        a1.push_back(3);
        print3(a1);
    }
    while(!a1.empty())
    {
        a1.pop_back();
        print3(a1);
    }
    cout << a4.front() << " " << a4.back() << endl;//访问首元素和末元素
    return 0;
}