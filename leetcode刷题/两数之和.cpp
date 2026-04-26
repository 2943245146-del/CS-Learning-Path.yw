#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;//哈希表，存储每个数字及其对应的索引
        for(int i=0;i<nums.size();i++)
        {
            auto it=hash.find(target-nums[i]);//从前往后找，如果当前数字的补数已经在哈希表中出现过了，那么就返回它们的索引 
            if(it!=hash.end())
            {
                return {it->second,i};
            }
            hash[nums[i]]=i;//把当前数字及其对应的索引加入哈希表中
        }
        return {};
    }
};