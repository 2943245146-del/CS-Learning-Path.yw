#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[4]={0,1,0,-1};//定义四个方向，右、下、左、上
        int dy[4]={1,0,-1,0};
        int m=matrix.size();
        int n=matrix[0].size();//m为矩阵的行数，n为矩阵的列数
        vector<int> p;
        int i=0;
        int j=0;
        int c=0;
        vector<vector<bool>> v(m+1, vector<bool>(n+1, false));//定义一个二维数组v，标记矩阵中的元素是否已经被访问过了，初始值为false
        for(int k=0;k<matrix.size()*matrix[0].size();k++)//循环matrix.size()*matrix[0].size()次，每次访问一个元素，直到访问完所有的元素为止
        {
            p.push_back(matrix[i][j]);
            v[i][j]=true;
            if (i+dx[c]>=m || j+dy[c]>=n || i+dx[c]<0 || j+dy[c]<0||v[i+dx[c]][j+dy[c]])//如果下一个元素越界了，或者下一个元素已经被访问过了，那么就说明需要改变方向了，就把c加1，取模4，得到下一个方向的索引
            {
                c=(c+1)%4;
            }
            i+=dx[c];
            j+=dy[c];
        }
        return p;
    }
};