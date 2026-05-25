/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)
题目描述
升序数组 stock 旋转后 (部分元素移到末尾), 找出最小元素。元素可能重复。
题目样例
示例1
- 输入: stock=[4,5,8,3,4]
- 输出: 3
示例2
- 输入: stock=[5,7,9,1,2]
- 输出: 1
题目思考
1. 如何利用旋转有序数组特性进行二分?
解决方案
思路
- 二分: 比较 stock[m] 与 stock[e]
  - stock[m] < stock[e]: 后半有序, 最小值在左半 (含m), e=m
  - stock[m] > stock[e]: 最小值在右半 (不含m), s=m+1
  - stock[m] == stock[e]: 无法判断, 退化 e--
复杂度
- 时间复杂度 O(logN)~O(N): 一般 O(logN), 全相等时退化 O(N)
- 空间复杂度 O(1): 常数空间
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int inventoryManagement(vector<int> &stock)
    {
        int s = 0, e = (int)stock.size() - 1;
        while (s < e)
        {
            int m = (s + e) >> 1;
            if (stock[m] < stock[e]) e = m;
            else if (stock[m] > stock[e]) s = m + 1;
            else --e;
        }
        return stock[s];
    }
};

int main()
{
    Solution sol;
    vector<int> s1 = {4, 5, 8, 3, 4};
    cout << sol.inventoryManagement(s1) << endl; // 3
    vector<int> s2 = {5, 7, 9, 1, 2};
    cout << sol.inventoryManagement(s2) << endl; // 1
    return 0;
}
