#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {//滑动窗口，哈希表，时间复杂度O(n)，空间复杂度O(1)
        int n1=s.size();
        int n2=p.size();
        vector<int> result;
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        for(auto& e:p)
        {
            hash1[e-'a']++;
        }
        int i=0;
        while(i<n1)
        {
            hash2[s[i]-'a']++;
            if(i>=n2-1) //到达窗口的右边界，通过窗口长度来判断是否到达窗口的右边界
            {
                if(hash2==hash1) result.push_back(i-n2+1);//vector可以直接比较是否相等
                hash2[s[i-n2+1]-'a']--;//通过窗口长度来判断窗口的左边界，并把窗口左边界的字符从哈希表中删除掉
            }
            i++;
        }
        return result;
    }
};