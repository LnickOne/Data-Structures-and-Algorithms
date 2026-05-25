/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/lwyVBB/)
题目描述
某种外星语也使用英文小写字母, 但字母表顺序 order 不同。
给定一组用外星语书写的单词 words, 及其字母表顺序 order,
只有当给定的单词在这种外星语中按字典序排列时返回 true, 否则返回 false。
题目样例
示例1
- 输入: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
- 输出: true
示例2
- 输入: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
- 输出: false
示例3
- 输入: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
- 输出: false
题目思考
1. 如何根据给定字母表来判断顺序?
2. 如何判断单词列表是否有序?
解决方案
思路
- 构造字符到下标的映射数组 rank[26]
- 自定义 le 函数: 逐字符比较两个单词, 遇到不同字符直接返回; 前缀相同时长度小的排在前面
- 遍历相邻单词对, 有一对不满足则返回 false
复杂度
- 时间复杂度 O(NM): N 是字符串数目, M 是字符串长度
- 空间复杂度 O(1): 固定大小的映射数组
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        int rank[26] = {};
        for (int i = 0; i < 26; i++) rank[order[i] - 'a'] = i;
        auto le = [&](const string &a, const string &b)
        {
            int n = min(a.size(), b.size());
            for (int i = 0; i < (int)n; i++)
            {
                int ra = rank[a[i] - 'a'], rb = rank[b[i] - 'a'];
                if (ra < rb) return true;
                if (ra > rb) return false;
            }
            return a.size() <= b.size();
        };
        for (int i = 1; i < (int)words.size(); i++)
            if (!le(words[i - 1], words[i])) return false;
        return true;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    vector<string> w1 = {"hello", "leetcode"};
    cout << sol.isAlienSorted(w1, "hlabcdefgijkmnopqrstuvwxyz") << endl; // true
    vector<string> w2 = {"word", "world", "row"};
    cout << sol.isAlienSorted(w2, "worldabcefghijkmnpqstuvxyz") << endl; // false
    vector<string> w3 = {"apple", "app"};
    cout << sol.isAlienSorted(w3, "abcdefghijklmnopqrstuvwxyz") << endl; // false
    return 0;
}
