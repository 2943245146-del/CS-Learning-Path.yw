#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>   
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int kk=k%n;
        vector<int> p;//创建一个新的数组p，把旋转后的元素放到p中，最后把p赋值给nums
        for(int i=n-kk;i<n;i++)
        {
            p.push_back(nums[i]);
        }
        for(int i=0;i<n-kk;i++)
        {
            p.push_back(nums[i]);
        }
        nums=p;
    }
};