#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char> p;//双端队列，存储当前最长无重复字符子串
        unordered_map<char,int> mp;//哈希表，存储当前最长无重复字符子串中每个字符出现的次数
        int n=s.size();
        int i=0;
        size_t ret=0;
        while(i<n)
        {
            while(mp[s[i]])//如果当前字符已经在当前最长无重复字符子串中出现过了，那么就把当前最长无重复字符子串的左边界向右移动，直到当前字符不再出现为止
            {
                int a=p.front();
                p.pop_front();
                mp[a]--;
            }
            p.push_back(s[i]);//把当前字符加入当前最长无重复字符子串中
            mp[s[i]]++;
            ret=max(ret,p.size());//更新当前最长无重复字符子串的长度
            i++;
        }
        return ret;
    }
};