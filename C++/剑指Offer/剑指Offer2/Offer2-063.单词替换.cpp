/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/UhWRSj/)
题目描述
给定词根列表 dictionary 和一个句子 sentence, 将句子中所有继承词替换为最短的词根。
题目样例
示例1
- 输入: dictionary=["cat","bat","rat"], sentence="the cattle was rattled by the battery"
- 输出: "the cat was rat by the bat"
示例2
- 输入: dictionary=["a","b","c"], sentence="aadsfasf absbs bbab cadsfafs"
- 输出: "a a b c"
题目思考
1. 需要使用什么数据结构?
解决方案
思路
- 将所有词根插入 Trie (前缀树)
- 对句子中每个单词, 在 Trie 中查找最短词根: 遇到 isWord=true 的节点立即返回该前缀
- 若未找到词根则保留原单词
复杂度
- 时间复杂度 O(C1+C2): C1 是词典字符总数, C2 是句子字符总数
- 空间复杂度 O(C1): Trie 存储词典所有字符
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Trie
{
    struct Node
    {
        Node *ch[26] = {};
        bool isWord = false;
    };
    Node *root;
public:
    Trie() : root(new Node()) {}
    void insert(const string &w)
    {
        Node *cur = root;
        for (char c : w)
        {
            int i = c - 'a';
            if (!cur->ch[i]) cur->ch[i] = new Node();
            cur = cur->ch[i];
        }
        cur->isWord = true;
    }
    string replace(const string &w)
    {
        Node *cur = root;
        for (int i = 0; i < (int)w.size(); i++)
        {
            int idx = w[i] - 'a';
            if (!cur->ch[idx]) break;
            cur = cur->ch[idx];
            if (cur->isWord) return w.substr(0, i + 1);
        }
        return w;
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie trie;
        for (auto &w : dictionary) trie.insert(w);
        istringstream ss(sentence);
        string tok, res;
        while (ss >> tok)
        {
            if (!res.empty()) res += " ";
            res += trie.replace(tok);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> d1 = {"cat", "bat", "rat"};
    cout << sol.replaceWords(d1, "the cattle was rattled by the battery") << endl;
    // the cat was rat by the bat
    vector<string> d2 = {"a", "b", "c"};
    cout << sol.replaceWords(d2, "aadsfasf absbs bbab cadsfafs") << endl;
    // a a b c
    return 0;
}
