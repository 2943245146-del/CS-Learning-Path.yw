#include<algorithm>
//二分查找STL
//auto it=lower_bound（数组名+1，数组名+n+1，x）返回第一个不小于x的元素位置
//*it就是这个元素的值
//*it-数组名就是这个元素的下标
//左闭右开区间
//如果没有找到，返回end()迭代器
//upper_bound返回第一个大于x的元素位置
//如果要查找一个数是否存在，可以用lower_bound和upper_bound的差值来判断