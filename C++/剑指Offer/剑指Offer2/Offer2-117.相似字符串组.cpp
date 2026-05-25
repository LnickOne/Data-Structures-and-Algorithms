/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/H6lPxb/)
题目描述
两字符串相似: 相等或交换两个不同位置字母后相等。给定字符串列表 strs (互为字母异位词), 求相似字符串组数。
题目样例
示例1
- 输入: strs=["tars","rats","arts","star"]
- 输出: 2 ({"tars","rats","arts"} 和 {"star"})
示例2
- 输入: strs=["omv","ovm"]
- 输出: 1
题目思考
1. 可以使用什么数据结构?
解决方案
思路
- 并查集: 两重循环判断字符串对是否相似 (不同字符数 <= 2), 相似则合并
- 最终统计不同祖先数量即为组数
复杂度
- 时间复杂度 O(N^2*(C+logN)): N 为字符串数, C 为字符串长度
- 空间复杂度 O(N): 并查集
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    vector<int> pre;
    int find(int x)
    {
        if (pre[x] != x) pre[x] = find(pre[x]);
        return pre[x];
    }
    void unite(int x, int y) { pre[find(x)] = find(y); }
    bool isSimilar(const string &a, const string &b)
    {
        int diff = 0;
        for (int i = 0; i < (int)a.size(); ++i)
            if (a[i] != b[i] && ++diff > 2) return false;
        return true;
    }
public:
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        pre.resize(n);
        for (int i = 0; i < n; ++i) pre[i] = i;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (isSimilar(strs[i], strs[j])) unite(i, j);
        int res = 0;
        for (int i = 0; i < n; ++i) if (find(i) == i) ++res;
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> s1 = {"tars","rats","arts","star"};
    cout << sol.numSimilarGroups(s1) << endl; // 2
    vector<string> s2 = {"omv","ovm"};
    cout << sol.numSimilarGroups(s2) << endl; // 1
    return 0;
}
