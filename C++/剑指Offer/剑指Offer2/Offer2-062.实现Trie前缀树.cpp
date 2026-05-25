/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/QC3q1f/)
题目描述
实现 Trie (前缀树) 类:
- Trie(): 初始化前缀树
- insert(word): 向前缀树中插入字符串 word
- search(word): 若 word 在前缀树中返回 true, 否则返回 false
- startsWith(prefix): 若有任意已插入单词以 prefix 为前缀返回 true, 否则返回 false
题目样例
示例1
- 输入: ["Trie","insert","search","search","startsWith","insert","search"]
         [[],["apple"],["apple"],["app"],["app"],["app"],["app"]]
- 输出: [null,null,true,false,true,null,true]
题目思考
1. 如何定义节点类?
解决方案
思路
- 每个节点包含 children[26] 数组 (对应 a-z) 和 isWord 标志
- insert: 遍历字符, 若子节点不存在则创建, 最后标记 isWord=true
- find: 遍历字符, 若子节点不存在返回 nullptr, 否则返回最终节点
- search: find != null && isWord; startsWith: find != null
复杂度
- 时间复杂度 O(NC): N 次操作, 每次操作字符串平均长度 C
- 空间复杂度 O(NC): 最差情况无重复节点
 */
#include <iostream>
#include <string>
using namespace std;

class Trie
{
    struct Node
    {
        Node *children[26] = {};
        bool isWord = false;
    };
    Node *root;
    Node *find(const string &w)
    {
        Node *cur = root;
        for (char c : w)
        {
            int idx = c - 'a';
            if (!cur->children[idx]) return nullptr;
            cur = cur->children[idx];
        }
        return cur;
    }
public:
    Trie() : root(new Node()) {}
    void insert(string word)
    {
        Node *cur = root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (!cur->children[idx]) cur->children[idx] = new Node();
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }
    bool search(string word)
    {
        Node *node = find(word);
        return node && node->isWord;
    }
    bool startsWith(string prefix)
    {
        return find(prefix) != nullptr;
    }
};

int main()
{
    cout << boolalpha;
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;    // true
    cout << trie.search("app") << endl;      // false
    cout << trie.startsWith("app") << endl;  // true
    trie.insert("app");
    cout << trie.search("app") << endl;      // true
    return 0;
}
