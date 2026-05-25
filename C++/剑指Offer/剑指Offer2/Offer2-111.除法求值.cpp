/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/vlzXQL/)
题目描述
给定变量对数组 equations 和实数值数组 values 表示 Ai/Bi=values[i], 求 queries 中每个 Cj/Dj 的值。无法确定则返回 -1.0。
题目样例
示例1
- 输入: equations=[["a","b"],["b","c"]], values=[2.0,3.0], queries=[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
- 输出: [6.0,0.5,-1.0,1.0,-1.0]
示例2
- 输入: equations=[["a","b"]], values=[0.5], queries=[["a","b"],["b","a"],["a","c"],["x","y"]]
- 输出: [0.5,2.0,-1.0,-1.0]
题目思考
1. 可以使用什么算法?
解决方案
思路
- 带权并查集: pre[x] = (祖先, x 相对祖先的倍数)
- find 进行路径压缩同时累乘倍数; union 合并时计算 px 相对 py 的新倍数
- query: 若两变量祖先相同则返回倍数之比, 否则 -1.0
复杂度
- 时间复杂度 O(N*logM): N 为方程数, M 为变量数
- 空间复杂度 O(M): pre 字典
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
    unordered_map<string, pair<string, double>> pre;
    pair<string, double> find(const string &x)
    {
        if (!pre.count(x))
            pre[x] = {x, 1.0};
        if (x != pre[x].first)
        {
            auto [px, pm] = find(pre[x].first);
            pre[x] = {px, pm * pre[x].second};
        }
        return pre[x];
    }
    void unite(const string &x, const string &y, double m)
    {
        auto [px, px_m] = find(x);
        auto [py, py_m] = find(y);
        pre[px] = {py, m * py_m / px_m};
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        pre.clear();
        for (int i = 0; i < (int)equations.size(); ++i)
            unite(equations[i][0], equations[i][1], values[i]);
        vector<double> res;
        for (auto &q : queries)
        {
            if (!pre.count(q[0]) || !pre.count(q[1]))
            {
                res.push_back(-1.0);
                continue;
            }
            auto [px, px_m] = find(q[0]);
            auto [py, py_m] = find(q[1]);
            res.push_back(px == py ? px_m / py_m : -1.0);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> eq1 = {{"a", "b"}, {"b", "c"}};
    vector<double> v1 = {2.0, 3.0};
    vector<vector<string>> q1 = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    auto r1 = sol.calcEquation(eq1, v1, q1);
    for (int i = 0; i < (int)r1.size(); ++i)
    {
        if (i)
            cout << ",";
        cout << r1[i];
    }
    cout << endl;
    // 6,0.5,-1,1,-1
    return 0;
}
