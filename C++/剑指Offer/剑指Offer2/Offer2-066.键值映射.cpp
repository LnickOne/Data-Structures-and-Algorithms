/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/z1R5dt/)
题目描述
实现 MapSum 类:
- insert(key, val): 插入 key-val 键值对, key 已存在则替换
- sum(prefix): 返回所有以 prefix 开头的 key 对应 val 的总和
题目样例
示例1
- 输入: ["MapSum","insert","sum","insert","sum"] [[],["apple",3],["ap"],["app",2],["ap"]]
- 输出: [null,null,3,null,5]
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- Trie + unordered_map<string,int>: 每个节点保存当前前缀的值总和 sm
- insert 时计算 diff = 新值 - 旧值 (key 不存在则为新值), 路径上每个节点的 sm 加 diff
- sum 时沿 prefix 路径走到末尾, 返回该节点的 sm
复杂度
- 时间复杂度 O(C): 每次操作只遍历字符串长度 C
- 空间复杂度 O(NC): Trie 存储所有字符
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class MapSum
{
    struct Node
    {
        Node *ch[26] = {};
        int sm = 0;
    };
    Node *root;
    unordered_map<string, int> k2v;
public:
    MapSum() : root(new Node()) {}
    void insert(string key, int val)
    {
        int diff = val - (k2v.count(key) ? k2v[key] : 0);
        k2v[key] = val;
        Node *cur = root;
        for (char c : key)
        {
            int i = c - 'a';
            if (!cur->ch[i]) cur->ch[i] = new Node();
            cur = cur->ch[i];
            cur->sm += diff;
        }
    }
    int sum(string prefix)
    {
        Node *cur = root;
        for (char c : prefix)
        {
            int i = c - 'a';
            if (!cur->ch[i]) return 0;
            cur = cur->ch[i];
        }
        return cur->sm;
    }
};

int main()
{
    MapSum ms;
    ms.insert("apple", 3);
    cout << ms.sum("ap") << endl; // 3
    ms.insert("app", 2);
    cout << ms.sum("ap") << endl; // 5
    return 0;
}
