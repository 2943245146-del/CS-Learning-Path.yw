#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {//时间复杂度O(n^2)，空间复杂度O(1)
        int n=height.size();
        int i=0;
        int sum=0;
        while(i<n)
        {
            int j=i+1;
            while(j<n&&height[j]<height[i]) j++;//找到右边第一个比当前高度大的柱子
            if(j==n)//如果没有找到，说明右边没有比当前高度大的柱子了，那么就把当前柱子高度减1，继续找
            {
                height[i]--;
                if(height[i]<=0) i++;
                continue;
            }
            int h=min(height[i],height[j]);
            for(int k=i;k<j;k++) sum+=h-height[k];
            i=j;
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(height)<<endl;
}