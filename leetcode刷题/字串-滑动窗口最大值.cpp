#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> p;
        multiset<int> m;
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            m.insert(nums[i]);//把当前数字加入到窗口中，multiset会自动排序，最大的数字会在最后面
            if(i>=k-1) //到达窗口的右边界，通过窗口长度来判断是否到达窗口的右边界
            {
                p.push_back(*m.rbegin());
                m.erase(m.find(nums[i-k+1]));
            }
            i++;
        }
        return p;
    }
};