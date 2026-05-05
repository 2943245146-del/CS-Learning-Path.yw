#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> p;//哈希表，key为前缀和，value为前缀和出现的次数
        int s=0,ans=0;
        for(int x:nums)
        {
            p[s]++;//把当前前缀和加入到哈希表中，方便后面判断一个前缀和是否存在
            s+=x;//计算前缀和
            if(p.find(s-k)!=p.end())
            {
                ans+=p[s-k];//如果当前前缀和减去k的值存在，那么就说明当前前缀和减去k的值是一个连续子数组的前缀和，那么就把这个连续子数组的个数加到答案中
            }
        }
        return ans;
    }
};