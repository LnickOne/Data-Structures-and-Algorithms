/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/WhsWhI/)
题目描述
给定未排序整数数组 nums, 找出数字连续的最长序列长度 (不要求在原数组中连续)。要求 O(n)。
题目样例
示例1
- 输入: nums=[100,4,200,1,3,2]
- 输出: 4 ([1,2,3,4])
示例2
- 输入: nums=[0,3,7,2,5,8,4,6,0,1]
- 输出: 9
题目思考
1. 如何实现时间复杂度为 O(n)?
解决方案
思路
- 将所有数字放入 unordered_set
- 只从序列开头 (x-1 不在集合中) 开始向后扩展计数, 避免重复遍历
复杂度
- 时间复杂度 O(N): 每个数字被遍历常数次
- 空间复杂度 O(N): 集合存储
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;
        for (int x : nums)
        {
            if (!st.count(x - 1))
            {
                int cnt = 0;
                while (st.count(x)) { ++x; ++cnt; }
                res = max(res, cnt);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(n1) << endl; // 4
    vector<int> n2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << sol.longestConsecutive(n2) << endl; // 9
    return 0;
}
