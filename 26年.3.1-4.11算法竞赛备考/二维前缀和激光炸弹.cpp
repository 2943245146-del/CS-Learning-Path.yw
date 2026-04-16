#include <iostream>
using namespace std;
const int N = 5010; // 根据数据范围，开到 5010 就足够了，最大 5000+偏移量
int s[N][N];        // 直接使用原数组作为前缀和数组
int main() {
    int n, r;
    cin >> n >> r;
    // 如果炸弹范围比地图还大，直接缩小到地图最大范围，避免后面枚举越界
    r = min(r, 5001); 
    int maxX = r, maxY = r; // 用于记录有目标的最大坐标，以缩小枚举范围
    for (int i = 1; i <=n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        x++;
        y++; // 坐标偏移，避免边界问题
        s[x][y] += v; // 同一个位置可能有多个目标，价值累加
        maxX = max(maxX, x);
        maxY = max(maxY, y);
    }
    // 计算二维前缀和：直接在原数组 s 上累加
    for (int i = 1; i <= maxX; i++) {
        for (int j = 1; j <= maxY; j++) {
            // 二维前缀和递推公式：s[i][j] = 原数组[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1]
            // 因为我们是在原数组上操作，所以公式稍微调整一下
            s[i][j] = s[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }
    int ans = 0;
    // 枚举所有可能的边长为 r 的正方形
    for (int i = r; i <= maxX; i++) {
        for (int j = r; j <= maxY; j++) {
            // 计算以 (i, j) 为右下角，边长为 r 的正方形内的总价值
            int sum = s[i][j] - s[i-r][j] - s[i][j-r] + s[i-r][j-r];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}