#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int ret=0;
        while(i<j)//双指针法，时间复杂度O(n)，空间复杂度O(1)
        {
            int sum=(j-i)*min(height[i],height[j]);
            ret=max(sum,ret);
            if(height[i]<=height[j]) i++;
            else j--;
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(height)<<endl;
}