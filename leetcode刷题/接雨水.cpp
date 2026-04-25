#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0;
        int sum=0;
        while(i<n)
        {
            int j=i+1;
            while(j<n&&height[j]<height[i]) j++;
            if(j==n)
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