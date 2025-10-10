#include <iostream>
#include <vector>
using namespace std;

// 创建链表结构
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};
// 通过数组创建链表
ListNode *createListNode(const std::vector<int> &arr)

{
    if (arr.size() == 0)
        return nullptr;
    ListNode *dummy = new ListNode(-1);
    ListNode *head = new ListNode(arr[0]); // 创建头节点
    dummy->next = head;                    // 临时指针指向头节点
    for (int i = 1; i < arr.size(); ++i)
    {
        head->next = new ListNode(arr[i]); // 创建新节点并链接到当前节点后面
        head = head->next;                 // 临时指针后移
    }
    return dummy->next; // 返回链表头节点
}
// 遍历并打印链表
void printListNode(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
// 获得链表的长度
int GetListLength(ListNode *head)
{
    int length = 0;
    while (head != nullptr)
    {
        length++;
        head = head->next;
    }
    return length;
}
// 克隆链表
ListNode *cloneList(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    // 创建一个新链表的头节点
    ListNode *newHead = new ListNode(head->val);
    ListNode *current = head->next;
    ListNode *newCurrent = newHead;
    // 遍历原链表并复制每个节点
    while (current != nullptr)
    {
        newCurrent->next = new ListNode(current->val);
        newCurrent = newCurrent->next;
        current = current->next;
    }
    return newHead;
}