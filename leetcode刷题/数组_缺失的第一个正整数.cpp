#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {//时间复杂度O(n)，空间复杂度O(n)
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,bool> mp;//哈希表，key为数字，value为这个数字是否在nums中出现过
        for(int i=1;i<=n;i++)
        {
            mp[nums[i-1]]=true;//把nums中的数字都放到哈希表中，方便后面判断一个数字是否在nums中出现过
        }
        for(int i=1;i<=n;i++)
        {
            if(!mp[i]) return i;//如果i不在nums中出现过，那么就说明i是第一个缺失的正整数，返回i
        }
        return n+1;
    }
};