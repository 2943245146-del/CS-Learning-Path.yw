#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> p;
        for(auto& e:nums)//把所有的数字都放到哈希表中，方便后面判断一个数字是否存在
        {
            p.insert(e);
        }
        int ss=0;
        for(auto& e:p)//遍历哈希表中的每个数字，如果这个数字的前一个数字不存在，那么就说明这个数字是一个连续序列的起点，然后就一直往后找，直到找不到下一个数字为止，记录这个连续序列的长度，更新最长连续序列的长度
        {
            int s=1;
            if(!p.count(e-1))
            {
                int a=e;
                while(p.count(a+1))//如果下一个数字存在，那么就说明这个数字是一个连续序列的一部分，就把这个数字加入到当前连续序列中，并继续往后找，直到找不到下一个数字为止
                {
                    a++;
                    s++;
                }
            }
            ss=max(ss,s);
        }
        return ss;
    }
};