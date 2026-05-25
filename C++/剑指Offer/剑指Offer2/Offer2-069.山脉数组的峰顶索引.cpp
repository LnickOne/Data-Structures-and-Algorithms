/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/B1IidL/)
题目描述
给定山峰数组 arr (先单调递增后单调递减), 返回峰顶下标 i。
题目样例
示例1
- 输入: arr = [0,1,0]
- 输出: 1
示例2
- 输入: arr = [1,3,5,4,2]
- 输出: 2
示例3
- 输入: arr = [24,69,100,99,79,78,67,36,26,19]
- 输出: 2
题目思考
1. 如何利用题目给出的条件优化时间复杂度?
解决方案
思路
- 二分查找: 区间 [1, n-2], 比较中点 m 与相邻元素
- m < m+1: 在左坡, 向右查找 (s = m+1)
- m-1 > m: 在右坡, 向左查找 (e = m-1)
- 否则: m 就是峰顶
复杂度
- 时间复杂度 O(logN): 二分查找
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int s = 1, e = arr.size() - 2;
        while (s <= e)
        {
            int m = (s + e) / 2;
            if (arr[m] < arr[m + 1]) s = m + 1;
            else if (arr[m - 1] > arr[m]) e = m - 1;
            else return m;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> a1 = {0, 1, 0};
    cout << sol.peakIndexInMountainArray(a1) << endl; // 1
    vector<int> a2 = {1, 3, 5, 4, 2};
    cout << sol.peakIndexInMountainArray(a2) << endl; // 2
    vector<int> a3 = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    cout << sol.peakIndexInMountainArray(a3) << endl; // 2
    return 0;
}
