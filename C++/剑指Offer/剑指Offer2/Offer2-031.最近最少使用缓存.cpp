/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/OrIXps/)
题目描述
设计和实现一个 LRU (最近最少使用) 缓存机制, 实现 LRUCache 类:
- LRUCache(int capacity): 以正整数 capacity 初始化 LRU 缓存
- int get(int key): 若 key 存在则返回其值, 否则返回 -1
- void put(int key, int value): 若 key 存在则变更其值; 若不存在则插入。达到容量上限时删除最久未使用的项。
题目样例
示例1
- 输入: ["LRUCache","put","put","get","put","get","put","get","get","get"]
         [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
- 输出: [null,null,null,1,null,-1,null,-1,3,4]
题目思考
1. 是否可以在 O(1) 时间复杂度内完成这两种操作?
解决方案
思路
- 双向链表 + unordered_map<int, Node*>
- 链表头部最新, 尾部最旧; map 记录 key 到节点的映射, 实现 O(1) 查找
- get/put 已存在节点: 先移除再插入头部 (moveToFront)
- put 新节点: 插入头部, 超容量时删除尾节点并从 map 中移除
复杂度
- 时间复杂度 O(1): 链表保证更新 O(1), map 保证查询 O(1)
- 空间复杂度 O(C): C 是 capacity
 */
#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache
{
    struct Node
    {
        int key, val;
        Node *pre, *nex;
        Node(int k, int v) : key(k), val(v), pre(nullptr), nex(nullptr) {}
    };
    int cap;
    Node *head, *tail;
    unordered_map<int, Node *> mp;

    void addFront(Node *node)
    {
        node->nex = head;
        node->pre = nullptr;
        if (head) head->pre = node;
        head = node;
        if (!tail) tail = node;
        mp[node->key] = node;
    }
    void removeNode(Node *node)
    {
        mp.erase(node->key);
        if (node->pre) node->pre->nex = node->nex;
        else head = node->nex;
        if (node->nex) node->nex->pre = node->pre;
        else tail = node->pre;
        node->pre = node->nex = nullptr;
    }
public:
    LRUCache(int capacity) : cap(capacity), head(nullptr), tail(nullptr) {}
    int get(int key)
    {
        if (!mp.count(key)) return -1;
        Node *node = mp[key];
        removeNode(node);
        addFront(node);
        return node->val;
    }
    void put(int key, int value)
    {
        if (mp.count(key))
        {
            removeNode(mp[key]);
            delete mp[key];
        }
        else if ((int)mp.size() == cap)
        {
            Node *old = tail;
            removeNode(old);
            delete old;
        }
        addFront(new Node(key, value));
    }
};

int main()
{
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl; // 1
    lru.put(3, 3);
    cout << lru.get(2) << endl; // -1
    lru.put(4, 4);
    cout << lru.get(1) << endl; // -1
    cout << lru.get(3) << endl; // 3
    cout << lru.get(4) << endl; // 4
    return 0;
}
