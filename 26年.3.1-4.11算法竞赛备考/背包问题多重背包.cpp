#include<iostream>
using namespace std;
const int N=110;
int n,m;
int x[N],w[N],v[N];
int f[N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>x[i]>>w[i]>>v[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            for(int k=0;k<=x[i]&&j>=k*w[i];k++)
            {
                f[j]=max(f[j],f[j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
//二进制优化
// #include <iostream>
// using namespace std;

// const int N = 20010;  // n * log(x) 最大约 20000
// int n, m;
// int w[N], v[N];
// int f[N];
// int cnt = 0;

// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) {
//         int x, weight, value;
//         cin >> x >> weight >> value;
//         // 二进制拆分
//         int k = 1;
//         while (k <= x) {
//             cnt++;
//             w[cnt] = k * weight;
//             v[cnt] = k * value;
//             x -= k;
//             k <<= 1;
//         }
//         if (x > 0) {
//             cnt++;
//             w[cnt] = x * weight;
//             v[cnt] = x * value;
//         }
//     }
    
//     // 01 背包
//     for (int i = 1; i <= cnt; i++) {
//         for (int j = m; j >= w[i]; j--) {
//             f[j] = max(f[j], f[j - w[i]] + v[i]);
//         }
//     }
    
//     cout << f[m] << endl;
//     return 0;
// }