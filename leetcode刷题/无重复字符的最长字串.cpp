#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char> p;
        unordered_map<char,int> mp;
        int n=s.size();
        int i=0;
        size_t ret=0;
        while(i<n)
        {
            while(mp[s[i]])
            {
                int a=p.front();
                p.pop_front();
                mp[a]--;
            }
            p.push_back(s[i]);
            mp[s[i]]++;
            ret=max(ret,p.size());
            i++;
        }
        return ret;
    }
};