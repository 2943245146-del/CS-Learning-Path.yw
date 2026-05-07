#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp,cnt;
        for(int i=0;i<t.size();i++)
        {
            ++mp[t[i]];
        }
        auto check = [&]() {
            for (auto& [ch, need] : mp) {
                if (cnt[ch] < need) return false;
            }
            return true;
        };
        int i=0,r=0;
        int len=0x3f3f3f3f,l=-1;
        while(r<s.size())
        {
            if(mp.find(s[r])!=mp.end())
            {
                cnt[s[r]]++;
            }
            while(check()&&i<=r)
            {
                if(len>r-i+1)
                {
                    len=r-i+1;
                    l=i;
                }
                if(mp.find(s[i])!=mp.end())
                {
                    cnt[s[i]]--;
                }
                i++;
            }
            r++;
        }
        return l==-1?"":s.substr(l,len);
    }
};