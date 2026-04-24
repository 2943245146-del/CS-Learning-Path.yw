#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=1;
        while(i<n)
        {
            if(nums[i]==0)//第一个指针指向零元素，第二个指针寻找下一个非零元素并交换
            {
                j=i+1;
                while(j<n&&nums[j]==0) j++;//第二个指针寻找下一个非零元素
                if(j<n) swap(nums[i],nums[j]);
            }
            i++;
        }
    }
};