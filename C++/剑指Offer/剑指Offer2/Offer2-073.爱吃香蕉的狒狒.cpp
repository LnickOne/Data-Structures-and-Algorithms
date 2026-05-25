/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/nZZqjQ/)
题目描述
有 N 堆香蕉, 每堆 piles[i] 根。狒狒以速度 K 根/小时吃香蕉 (每小时吃一堆中至多 K 根)。
警卫 H 小时后回来, 返回能在 H 小时内吃完所有香蕉的最小速度 K。
题目样例
示例1
- 输入: piles=[3,6,7,11], H=8
- 输出: 4
示例2
- 输入: piles=[30,11,23,4,20], H=5
- 输出: 30
示例3
- 输入: piles=[30,11,23,4,20], H=6
- 输出: 23
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 速度增大时吃完时间单调递减, 可以二分查找满足要求的最小速度
- 速度范围 [1, max(piles)]; 对每个速度验证是否能在 H 小时内吃完
- 验证: 每堆需要 ceil(p/speed) = (p+speed-1)/speed 小时
复杂度
- 时间复杂度 O(NlogM): N 是堆数, M 是最大香蕉数
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    bool isValid(vector<int> &piles, long long speed, int h)
    {
        long long hour = 0;
        for (int p : piles)
        {
            hour += (p + speed - 1) / speed;
            if (hour > h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int s = 1, e = *max_element(piles.begin(), piles.end()), res = e;
        while (s <= e)
        {
            int m = (s + e) / 2;
            if (isValid(piles, m, h)) { res = m; e = m - 1; }
            else s = m + 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> p1 = {3, 6, 7, 11};
    cout << sol.minEatingSpeed(p1, 8) << endl; // 4
    vector<int> p2 = {30, 11, 23, 4, 20};
    cout << sol.minEatingSpeed(p2, 5) << endl; // 30
    cout << sol.minEatingSpeed(p2, 6) << endl; // 23
    return 0;
}
