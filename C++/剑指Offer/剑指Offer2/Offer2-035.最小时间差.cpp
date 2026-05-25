/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/569nqc/)
题目描述
给定一个 24 小时制 (HH:MM) 的时间列表, 找出列表中任意两个时间的最小时间差并以分钟数表示。
题目样例
示例1
- 输入: timePoints = ["23:59","00:00"]
- 输出: 1
示例2
- 输入: timePoints = ["00:00","23:59","00:00"]
- 输出: 0
题目思考
1. 如何快速得到两个时间的时间差?
2. 如何进一步优化时间复杂度?
解决方案
思路
- 鸽巢原理: 若时间数超过 24*60=1440, 必然有重复, 直接返回 0
- 将时间转换成相比 0 点 0 分的分钟数, 排序后依次比较相邻时间差
- 额外比较首尾跨天的时间差 (第一个时间加 24*60 减最后一个时间)
复杂度
- 时间复杂度 O(NlogN): 排序
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        if ((int)timePoints.size() > 24 * 60) return 0;
        auto toMin = [](const string &t)
        {
            return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
        };
        sort(timePoints.begin(), timePoints.end());
        int first = toMin(timePoints[0]);
        int last = toMin(timePoints.back());
        int res = 24 * 60 + first - last;
        int pre = first;
        for (int i = 1; i < (int)timePoints.size(); i++)
        {
            int cur = toMin(timePoints[i]);
            res = min(res, cur - pre);
            pre = cur;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> t1 = {"23:59", "00:00"};
    cout << sol.findMinDifference(t1) << endl; // 1
    vector<string> t2 = {"00:00", "23:59", "00:00"};
    cout << sol.findMinDifference(t2) << endl; // 0
    vector<string> t3 = {"05:31", "22:08", "00:35"};
    cout << sol.findMinDifference(t3) << endl; // 147 (00:35->05:31)
    return 0;
}
