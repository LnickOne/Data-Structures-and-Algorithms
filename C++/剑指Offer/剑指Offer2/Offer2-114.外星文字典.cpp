/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/Jf1JuT/)
题目描述
给定按外星文字母顺序排序的字符串列表 words, 还原字母顺序。若不存在合法顺序返回 "", 若有多种返回任意一种。
题目样例
示例1
- 输入: words=["wrt","wrf","er","ett","rftt"]
- 输出: "wertf"
示例2
- 输入: words=["z","x"]
- 输出: "zx"
示例3
- 输入: words=["z","x","z"]
- 输出: "" (不合法)
题目思考
1. 需要什么算法?
解决方案
思路
- 拓扑排序: 比较相邻单词找出字母顺序关系, 建立有向图和入度表
- 若后词是前词前缀且更短则非法; 若出现环则返回 ""
- 拓扑排序输出结果, 长度不等于字符集大小则返回 ""
复杂度
- 时间复杂度 O(MN+C): M 为单词平均长度, N 为单词数, C 为字符数
- 空间复杂度 O(N+C): 邻接表和入度表
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
    string alienOrder(vector<string> &words)
    {
        unordered_map<char, unordered_set<char>> nxt;
        unordered_map<char, int> indegree;
        for (auto &w : words)
            for (char c : w)
                if (!indegree.count(c))
                    indegree[c] = 0;
        for (int i = 1; i < (int)words.size(); ++i)
        {
            auto &a = words[i - 1], &b = words[i];
            int len = min(a.size(), b.size());
            bool found = false;
            for (int j = 0; j < len; ++j)
            {
                if (a[j] != b[j])
                {
                    if (nxt[b[j]].count(a[j]))
                        return "";
                    if (!nxt[a[j]].count(b[j]))
                    {
                        nxt[a[j]].insert(b[j]);
                        ++indegree[b[j]];
                    }
                    found = true;
                    break;
                }
            }
            if (!found && a.size() > b.size())
                return "";
        }
        queue<char> q;
        for (auto &[c, d] : indegree)
            if (d == 0)
                q.push(c);
        string res;
        while (!q.empty())
        {
            char cur = q.front();
            q.pop();
            res += cur;
            for (char nc : nxt[cur])
                if (--indegree[nc] == 0)
                    q.push(nc);
        }
        return res.size() == indegree.size() ? res : "";
    }
};

int main()
{
    Solution sol;
    vector<string> w1 = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << sol.alienOrder(w1) << endl; // wertf
    vector<string> w2 = {"z", "x"};
    cout << sol.alienOrder(w2) << endl; // zx
    vector<string> w3 = {"z", "x", "z"};
    cout << sol.alienOrder(w3) << endl; // ""
    return 0;
}
