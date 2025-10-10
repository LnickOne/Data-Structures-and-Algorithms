#include <iostream>
#include <vector>
#include <algorithm>
#include "ListNode.h"
using namespace std;
/*
给定一个节点数为n的无序单链表，对其按升序排序。
输入：
[1,3,2,4,5]
复制
返回值：
{1,2,3,4,5}
复制
示例2
输入：
[-1,0,-2]
复制
返回值：
{-2,-1,0}
*/
class Solution
{
public:
    ListNode *sortInList(ListNode *head)
    {
        ListNode *p = head;
        vector<int> arr;
        while (p != nullptr)
        {
            arr.push_back(p->val);
            p = p->next;
        }
        sort(arr.begin(), arr.end());
        return creatListNode(arr);
    }
    ListNode *creatListNode(vector<int> arr)
    {
        if (arr.empty())
            return nullptr;
        ListNode *head = new ListNode(arr[0]);
        ListNode *node = head;
        for (int i = 1; i < arr.size(); i++)
        {
            node->next = new ListNode(arr[i]);
            node = node->next;
        }
        return head;
    }
};

int main()
{
    return 0;
}