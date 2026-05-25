/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/SsGoHC/)
题目描述
以数组 intervals 表示若干区间, 合并所有重叠区间, 返回不重叠的区间数组。
题目样例
示例1
- 输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
- 输出: [[1,6],[8,10],[15,18]]
示例2
- 输入: intervals = [[1,4],[4,5]]
- 输出: [[1,5]]
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 按区间起点排序, 排序后有重叠的区间一定相邻
- 遍历区间: 若与 res 末尾区间有重叠 (末尾终点 >= 当前起点) 则合并 (更新末尾终点)
- 否则将当前区间追加到 res
复杂度
- 时间复杂度 O(NlogN): 排序
- 空间复杂度 O(1): 不计返回值
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto &iv : intervals)
        {
            if (!res.empty() && res.back()[1] >= iv[0])
                res.back()[1] = max(res.back()[1], iv[1]);
            else
                res.push_back(iv);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    auto print = [](vector<vector<int>> &v) {
        for (auto &p : v) cout << "[" << p[0] << "," << p[1] << "] "; cout << endl;
    };
    vector<vector<int>> iv1 = {{1,3},{2,6},{8,10},{15,18}};
    auto r1 = sol.merge(iv1);
    print(r1); // [1,6] [8,10] [15,18]
    vector<vector<int>> iv2 = {{1,4},{4,5}};
    auto r2 = sol.merge(iv2);
    print(r2); // [1,5]
    return 0;
}
