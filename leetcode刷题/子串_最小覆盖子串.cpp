#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp,cnt;//哈希表，key为字符，value为字符出现的次数
        for(int i=0;i<t.size();i++)
        {
            ++mp[t[i]];//mp记录t中每个字符出现的次数
        }
        auto check = [&]() {//lambda表达式，检查当前窗口中的字符是否满足t中字符的要求
            for (auto& [ch, need] : mp) {
                if (cnt[ch] < need) return false;
            }
            return true;
        };
        int i=0,r=0;//i为窗口的左边界，r为窗口的右边界
        int len=0x3f3f3f3f,l=-1;//len为最小窗口的长度，l为最小窗口的左边界.初始值为-1表示没有找到满足条件的窗口
        while(r<s.size())
        {
            if(mp.find(s[r])!=mp.end())//如果s[r]在t中出现过，那么就把s[r]加入到当前窗口中，并更新cnt中s[r]的出现次数
            {
                cnt[s[r]]++;
            }
            while(check()&&i<=r)//如果当前窗口中的字符满足t中字符的要求，那么就说明当前窗口是一个满足条件的窗口，就记录这个窗口的长度和左边界，并把窗口的左边界向右移动，直到不满足条件为止
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