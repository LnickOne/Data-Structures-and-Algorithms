/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/iSwD2y/)
题目描述
给定单词数组 words, 返回成功对 words 进行编码的最小助记字符串 s 的长度。
若字符串 a 是字符串 b 的后缀, 则两者可以共用同一助记字符串 (编码中计一次)。
题目样例
示例1
- 输入: words = ["time","me","bell"]
- 输出: 10 (s = "time#bell#")
示例2
- 输入: words = ["t"]
- 输出: 2
题目思考
1. 需要使用什么数据结构?
解决方案
思路
- 将单词反转后插入 Trie (后缀转前缀), 从大到小按长度排序先插入长的
- 插入时若路径已存在 (isExist=true) 则该单词是之前某单词的后缀, 无需额外编码
- 否则该单词需要新的助记字符串, 总长度加 len+1 (#号)
复杂度
- 时间复杂度 O(NlogN+NC): 排序 O(NlogN) + Trie 插入 O(NC)
- 空间复杂度 O(NC): Trie 存储所有字符
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Trie
{
    struct Node { Node *ch[26] = {}; };
    Node *root;
public:
    Trie() : root(new Node()) {}
    int insert(const string &w)
    {
        Node *cur = root;
        bool isExist = true;
        for (char c : w)
        {
            int i = c - 'a';
            if (!cur->ch[i]) { isExist = false; cur->ch[i] = new Node(); }
            cur = cur->ch[i];
        }
        return isExist ? 0 : (int)w.size() + 1;
    }
};

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() > b.size();
        });
        Trie trie;
        int res = 0;
        for (auto &w : words)
        {
            string rev(w.rbegin(), w.rend());
            res += trie.insert(rev);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> w1 = {"time", "me", "bell"};
    cout << sol.minimumLengthEncoding(w1) << endl; // 10
    vector<string> w2 = {"t"};
    cout << sol.minimumLengthEncoding(w2) << endl; // 2
    vector<string> w3 = {"me", "time"};
    cout << sol.minimumLengthEncoding(w3) << endl; // 6 (time#)-> wait, me is suffix of time -> 5+1=6? no "time#"=5, me shares, so 5. Let me recheck: "time#" = 5+1=6? no: t-i-m-e-# = 5 chars.
    return 0;
}
