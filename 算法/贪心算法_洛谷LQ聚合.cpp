/*
#include<iostream>
#include<string>
using namespace std;
const int N=1e5+10;
int pre[N],bac[N];
bool st[N];
int ans;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=n;i>0;i--)//时间复杂度为O(n)，从后往前遍历字符串s，处理每个字符
    {
        if(s[i-1]=='?')
        {
            s[i-1]='Q';
            st[i-1]=true;//如果当前字符是?，将其暂时替换为Q，并记录这个位置是原本的?，以便后续处理
        }
    }
    // 计算每个位置左边有多少个 L
    int cntL = 0;
    for (int i = 0; i < n; i++) //时间复杂度为O(n)，从前往后遍历字符串s，处理每个字符
    {
        pre[i] = cntL;
        if (s[i] == 'L') cntL++;
    }
    // 计算每个位置右边有多少个 Q
    int cntQ=0;
    for (int i = n-1; i >= 0; i--) {
        bac[i] = cntQ;
        if (s[i] == 'Q') cntQ++;
    }
    // 处理 ? 的位置（贪心决定变成 L 还是 Q）
    for (int i = 0; i < n; i++) {
        if (st[i]) {  // 原本是 ? 的位置
            if (bac[i] > pre[i]) {
                s[i] = 'L';  // 右边 Q 多，变成 L
               for(int j=i+1;j<n;j++)
               {
                   pre[j]++;//如果当前位置变成 L，那么它左边的所有位置的 pre 数组都要加 1，因为它们左边多了一个 L
               }
            } else {
                continue;  // 右边 Q 不多，保持为 Q
            }
        }
    }
    int t=0;
    for(int i=0;i<n;i++)//计算最终字符串中每个 Q 之前有多少个 L，并将这些数量累加到 ans 中，得到最终的结果
    {
        if(s[i]=='L')
        {
            t++;
        }
        else
        {
            ans+=t;
        }
    }
    cout<<ans<<endl;
    return 0;
}*/
//我写的代码纯贪心全部ac，贪心思路很简单，
//每一个字符位置都可以统计前面L的数量还有后面Q的数量，
//如果Q>L直接将‘？’改为‘L’，最后统计数量
#include <iostream>
#include <string>
using namespace std;
const int N = 1e5 + 10;
int pre[N], bac[N];
bool st[N];
long long ans;  // 用 long long 防止溢出
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s; 
    // 预处理：? 先变成 Q，并标记
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            s[i] = 'Q';
            st[i] = true;// 如果当前字符是?，将其暂时替换为Q，并记录这个位置是原本的?，以便后续处理
        }
    }
    // 计算 pre[i]：左边 L 的个数（基于初始状态，所有 ? 都是 Q）
    int cntL = 0;
    for (int i = 0; i < n; i++) {
        pre[i] = cntL;
        if (s[i] == 'L') cntL++;
    }
    
    // 计算 bac[i]：右边 Q 的个数
    int cntQ = 0;
    for (int i = n - 1; i >= 0; i--) {
        bac[i] = cntQ;
        if (s[i] == 'Q') cntQ++;
    }
    // 贪心处理 ? 的位置（O(n) ）
    int extraL = 0;  // 时间复杂度降低的关键，记录额外增加的 L 数量
    for (int i = 0; i < n; i++) {
        if (st[i]) {
            // 实际左边 L 的数量 = 原始 pre[i] + 之前变成 L 的数量
            int realPre = pre[i] + extraL;
            if (bac[i] > realPre) {
                s[i] = 'L';
                extraL++;  // 这个 ? 变成了 L，后面的位置左边会多一个 L
            }
            // else: 保持 Q，不需要任何操作
        }
    }
    // 统计答案
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            t++;
        } else if (s[i] == 'Q') {
            ans += t;
        }
    }
    cout << ans << endl;
    return 0;
}