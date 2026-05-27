/* 题目难度: 中等
[原题链接](https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/)
题目描述
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
- -10000 <= Node.val <= 10000
- Node.random 为空（null）或指向链表中的节点。
- 节点数目不超过 1000 。
题目样例
示例
输入
head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出
[[7,null],[13,0],[11,4],[10,2],[1,0]]
题目思考
1. 如何处理 random 指针?
解决方案
思路
- 如果只有 next 指针的话很简单, 我们只需要对每个节点新建一个相同值的节点, 并保持指向关系, 逐个遍历过去即可
- 现在多了个 random 指针, 想要定位新的指向的节点, 一个比较自然的想法就是额外维护一个老节点到新节点的映射关系, 可以用字典来实现
- 第一遍遍历, 就只关注 next 部分, 并建立好映射关系
- 第二遍遍历, 考虑 random 部分, 找到对应的新链表的节点, 然后当前节点的 random 指针指向它即可
复杂度
- 时间复杂度 `O(N)`
  - 每个节点只需要遍历两次
- 空间复杂度 `O(N)`
  - 额外需要一个字典
*/
#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        unordered_map<Node *, Node *> maps;
        // 第一遍遍历, 建立新的链表, 以及老节点到新节点的映射关系
        Node *copyHead = new Node(head->val);
        Node *origin = head;
        Node *copy = copyHead;
        maps[origin] = copy;
        while (origin->next)
        {
            // 新建下一个节点, 并建立 next 关系
            copy->next = new Node(origin->next->val);
            origin = origin->next;
            copy = copy->next;
            maps[origin] = copy;
        }
        // 第二遍遍历, 处理 random 指针部分
        origin = head;
        copy = copyHead;
        while (origin)
        {
            if (origin->random)
            {
                // 如果老节点 random 指针指向非空, 就将当前新节点也指向随机节点对应的新节点
                copy->random = maps[origin->random];
            }
            origin = origin->next;
            copy = copy->next;
        }
        return copyHead;
    }
};

// 辅助函数: 打印复杂链表 (值和 random 值)
void printNodeList(Node *head)
{
    Node *cur = head;
    while (cur)
    {
        cout << "[" << cur->val << ",";
        if (cur->random)
            cout << cur->random->val;
        else
            cout << "null";
        cout << "]";
        if (cur->next)
            cout << " -> ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    Solution s;

    // 示例: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    // 构建原始链表
    Node *n1 = new Node(7);
    Node *n2 = new Node(13);
    Node *n3 = new Node(11);
    Node *n4 = new Node(10);
    Node *n5 = new Node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    // 设置 random 指针
    n1->random = nullptr;
    n2->random = n1; // index 0
    n3->random = n5; // index 4
    n4->random = n3; // index 2
    n5->random = n1; // index 0

    cout << "Original: ";
    printNodeList(n1);

    Node *copied = s.copyRandomList(n1);
    cout << "Copied:   ";
    printNodeList(copied);

    // 验证深拷贝: 修改原链表不影响拷贝
    n1->val = 99;
    cout << "After modifying original head val to 99:" << endl;
    cout << "Original: ";
    printNodeList(n1);
    cout << "Copied:   ";
    printNodeList(copied);

    return 0;
}
