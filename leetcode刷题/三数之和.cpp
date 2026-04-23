#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> p;
        sort(nums.begin(),nums.end());//排序
        int s=nums.size();
        for(int k=0;k<s-2;k++)//固定一个数，剩下的两个数用双指针法
        {
            if(k>0&&nums[k]==nums[k-1]) continue;//去重前保留一次重复元素
            int i=k+1;
            int j=s-1;
            while(i<j)//双指针法
            {
                int sum=nums[k]+nums[i]+nums[j];
                if(sum==0) 
                {
                    p.push_back({nums[k],nums[i],nums[j]});
                    while(i<j&&nums[i+1]==nums[i]) i++;//去重前保留一次重复元素
                    while(i<j&&nums[j]==nums[j-1]) j--;
                    i++;
                    j--;
                }
                else if(sum<0) i++;
                else j--;
            }
        }
        return p;
    }
};//双指针法，时间复杂度O(n^2)，空间复杂度O(1)
int main()
{
    Solution s;
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> p=s.threeSum(nums);
    for(int i=0;i<p.size();i++)
    {
        for(int j=0;j<p[i].size();j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}