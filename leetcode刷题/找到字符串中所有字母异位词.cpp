#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
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
            if(i>=n2-1) 
            {
                if(hash2==hash1) result.push_back(i-n2+1);
                hash2[s[i-n2+1]-'a']--;
            }
            i++;
        }
        return result;
    }
};