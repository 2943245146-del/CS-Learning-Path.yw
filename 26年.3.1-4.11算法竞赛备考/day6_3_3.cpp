#include<iostream>
#include<deque>//改用双端队列
using namespace std;
int main()
{
    int m,n,x;
    cin>>m>>n;
    deque<int> p;
    int s=0;
    int f=0;
    for(int i=0;i<n;i++)
    {
            cin>>x;
            for(int e:p)
            {
                if(e==x)
                {
                    f=1;
                }
            }
            if(f==0)
            {
                p.push_back(x);
                s++;
            }
            f=0;
        if(p.size()==m+1)
        {
            p.pop_front();
        }
    }
    cout << s << endl;
    return 0;
}
