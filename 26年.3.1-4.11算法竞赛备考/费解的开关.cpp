#include<iostream>
#include<cstring>
using namespace std;
//费解开关
const int N=10;
int n=5;
int a[N];//开关状态
int t[N];
int calc(int x)
{
    int cnt=0;
    while(x)
    {
        cnt++;
        x=x&(x-1);
    }
    return cnt;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        //多组测试前一定记得清空数据
        memset(a,0,sizeof a);//将数组a的所有元素都设置为0
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char x;
                cin>>x;
                if(x=='0') a[i]|=1<<j;
            }
        }
        int ret=0x3f3f3f3f;
        for(int i=0;i<(1<<n);i++)//枚举所有可能的开关组合
        {
            memcpy(t,a,sizeof a);
            int push=i;
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                cnt+=calc(push);
                t[j]=t[j]^push^(push<<1)^(push>>1);
                t[j+1]=t[j+1]^push;
                t[j]=t[j]&((1<<n)-1);//保证t[j]只保留前n位
                push=t[j];
            }
            if(t[n-1]==0)
            {
            ret=min(ret,cnt);
            }
        }
        if(ret>6)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<ret<<endl;
        }
    }
        return 0;
}
