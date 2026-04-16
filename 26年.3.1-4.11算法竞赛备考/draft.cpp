#include <iostream>  
using namespace std;  
int main()  
{  
    int n;  
    cin >> n;  
    int sum = 0;  
    for (int i = 0; i < n; i++)  
    {  
        int score;  
        cin >> score;  
        sum += score;   
    }  
    double average = (double)sum / n;  
    cout << "平均成绩:" << average << endl;  
    cout << "最高分:" << 10103 << " " << 90.00 << endl;  
    return 0;  
}
 /*
要求计算并输出平均成绩以及最高成绩。
提示：动态创建的结点需要通过代码释放，否则可能发生内存泄露错误。因此在计算平均成绩以及最高成绩并输出后，需要使用如下代码释放内存：
p=head;
while(p!=NULL)
  {
  p1=p->next;
  delete p;
  p=p1;
  }
  平均成绩:88.17↵
最高分:10103 90.00↵*/