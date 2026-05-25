/*
> 题目难度: 简单

> [原题链接](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)


题目描述

输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

- 1 <= target <= 10^5

题目样例

示例

- 输入：target = 9
- 输出：[[2,3,4],[4,5]]

- 输入：target = 15
- 输出：[[1,2,3,4,5],[4,5,6],[7,8]]

题目思考

1. 满足条件的序列长度有什么规律?
2. 时间复杂度可以小于 O(target)吗?

解决方案

思路

- 一个比较容易想到的思路是利用滑动窗口, 维护起点和终点以及当前窗口的和
- 然后根据当前窗口和与 target 的关系来决定起点和终点的移动
  - `窗口和 > target`: 起点右移
  - `窗口和 = target`: 起点右移, 并将当前起点终点加入结果集中
  - `窗口和 < target`: 终点右移
- 注意终点上限是`target/2+1`, 对应长度为 2 的情况

复杂度

- 时间复杂度 O(target): 终点至少需要遍历到`target/2+1`
- 空间复杂度 O(1): 只使用了几个变量(结果数组使用的空间不计入内)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> res;
        int l = 1, r = 2;
        int sum = l + r;
        while (l < r)
        {
            if (sum == target)
            {
                vector<int> seq;
                for (int k = l; k <= r; k++)
                {
                    seq.push_back(k);
                }
                res.push_back(seq);
                sum -= l;
                l++;
            }
            else if (sum < target)
            {
                r++;
                sum += r;
            }
            else
            {
                sum -= l;
                l++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> res1 = sol.findContinuousSequence(9);
    for (const auto &seq : res1)
    {
        cout << "[";
        for (int i = 0; i < (int)seq.size(); i++)
        {
            if (i > 0)
                cout << ",";
            cout << seq[i];
        }
        cout << "] ";
    }
    cout << endl; // [2,3,4] [4,5]

    vector<vector<int>> res2 = sol.findContinuousSequence(15);
    for (const auto &seq : res2)
    {
        cout << "[";
        for (int i = 0; i < (int)seq.size(); i++)
        {
            if (i > 0)
                cout << ",";
            cout << seq[i];
        }
        cout << "] ";
    }
    cout << endl; // [1,2,3,4,5] [4,5,6] [7,8]

    return 0;
}
