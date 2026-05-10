#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int N = 1e4 + 10;
        int* a = new int[N]();//创建差分数组，初始值为0
        vector<vector<int>> p;
        int n = 0;
        int l = 0x3f3f3f3f;//n为差分数组的长度，l为差分数组的左边界
        unordered_map<int, int> mp;//哈希表，key为区间的左边界，value为区间的数量
        for (auto& e : intervals) {//遍历每个区间，把区间的左边界加1，右边界加-1，更新差分数组，同时更新差分数组的长度和左边界
            a[e[0]]++;
            a[e[1]]--;
            n = max(n, e[1]);
            l = min(l, e[0]);
            if (e[0] == e[1])//如果区间的左边界和右边界相同，那么就说明这个区间是一个点，单独处理
                mp[e[0]]++;
        }
        int sum = a[l];
        while (l <= n) {
            int j = l;
            if (mp.find(j) != mp.end() && !a[j]) {//如果j是一个点，并且差分数组在j的位置为0，那么就说明这个点是一个区间的左边界，也是一个区间的右边界，单独处理
                sum += a[j + 1];
                a[j + 1] = a[j] + a[j + 1];
                p.push_back({j, j});
                l++;
                continue;
            }
            while (j <= n && a[j]) {//更新区间
                sum += a[j + 1];
                a[j + 1] = a[j] + a[j + 1];
                if (mp.find(j) != mp.end() && !a[j]&&j!=p.back()[1])
                    p.push_back({j, j});
                j++;
                if (sum == 0)
                    p.push_back({l, j});
            }
            l = j;
            while (l <= n && !a[l]) {//更新区间
                if (mp.find(l) != mp.end() && !a[l]&&l!=p.back()[1])
                    p.push_back({l, l});
                sum += a[l + 1];
                a[l + 1] = a[l] + a[l + 1];
                l++;
            }
        }
        return p;
    }
};