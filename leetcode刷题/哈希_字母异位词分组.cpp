#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> p;
        unordered_map<string,vector<string>> hash;//哈希表，key为排序后的字符串，value为原字符串的集合
        for(auto& t:strs)
        {
            string key=t;
            sort(key.begin(),key.end());
            hash[key].push_back(t);
        }
        for(auto it:hash)
        {
            p.push_back(it.second);
        }
        return p;
    }
};