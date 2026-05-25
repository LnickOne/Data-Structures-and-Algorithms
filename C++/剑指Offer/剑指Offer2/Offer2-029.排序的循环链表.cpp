/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/4ueAj6/)
题目描述
给定循环单调非递减链表中的一个节点 head (不一定是最小值节点), 向其中插入一个值为 insertVal 的新节点,
使链表仍然是有序的, 并返回插入的新节点。
若链表为空则创建一个自循环节点。
题目样例
示例1
- 输入: head = [3,4,1], insertVal = 2
- 输出: [3,4,1,2] (插入到 1 和 3 之间)
示例2
- 输入: head = [], insertVal = 1
- 输出: [1]
示例3
- 输入: head = [1], insertVal = 0
- 输出: [1,0]
题目思考
1. 插入位置有哪几种情况?
解决方案
思路
- 情况1: 链表为空, 创建自环节点直接返回
- 遍历链表维护当前节点 cur 和最大值节点 mx, 三种插入情况:
  - 情况2 (正常区间): cur->val <= insertVal <= cur->next->val, 在 cur 和 cur->next 之间插入
  - 情况3 (越界): 遍历一圈后未找到合适位置 (insertVal 大于所有值或小于所有值), 在最大值节点之后插入
  - 情况4 (所有值相等): 同样在最大值节点之后插入
- mx 记录最后一个出现的最大值节点 (更新条件 cur->val >= mx->val), 确保插入位置正确
复杂度
- 时间复杂度 O(N): 遍历链表一圈
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int v = 0) : val(v), next(nullptr) {}
};

class Solution
{
public:
    Node *insert(Node *head, int insertVal)
    {
        Node *node = new Node(insertVal);
        if (!head)
        {
            node->next = node;
            return node;
        }
        Node *cur = head, *mx = head;
        while (true)
        {
            if (cur->val <= insertVal && insertVal <= cur->next->val)
            {
                node->next = cur->next;
                cur->next = node;
                return head;
            }
            if (cur->val >= mx->val)
                mx = cur;
            cur = cur->next;
            if (cur == head)
                break;
        }
        node->next = mx->next;
        mx->next = node;
        return head;
    }
};

int main()
{
    Solution s;
    // 示例1: [3,4,1] 插入 2
    Node *n1 = new Node(3), *n2 = new Node(4), *n3 = new Node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n1;
    s.insert(n1, 2);
    Node *cur = n1;
    do
    {
        cout << cur->val << " ";
        cur = cur->next;
    } while (cur != n1);
    cout << endl; // 3 4 1 2
    // 清理
    n3->next = nullptr;
    while (n1)
    {
        Node *t = n1->next;
        delete n1;
        n1 = t;
    }
    // 示例2: 空链表插入 1
    Node *res = s.insert(nullptr, 1);
    cout << res->val << endl; // 1
    delete res;
    // 示例3: [1] 插入 0
    Node *m1 = new Node(1);
    m1->next = m1;
    s.insert(m1, 0);
    cur = m1;
    do
    {
        cout << cur->val << " ";
        cur = cur->next;
    } while (cur != m1);
    cout << endl; // 1 0
    m1->next->next = nullptr;
    delete m1->next;
    delete m1;
    return 0;
}
