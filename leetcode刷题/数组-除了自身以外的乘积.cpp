#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        int n=nums.size();
        deque<int> prefix;
        deque<int> suffix;
        int s=1;
        for(int i=0;i<n;i++)
        {
            s*=nums[i];
            prefix.push_back(s);//prefix[i]存储nums[0]到nums[i]的乘积
        }
        s=1;
        for(int i=n-1;i>=0;i--)
        {
            s*=nums[i];
            suffix.push_front(s);//suffix[i]存储nums[i]到nums[n-1]的乘积
        }
        for(int i=0;i<n;i++)
        {
            int temp=1;
            if(i>0) temp*=prefix[i-1];
            if(i<n-1) temp*=suffix[i+1];
            answer.push_back(temp);
        }
        return answer;
    }
};