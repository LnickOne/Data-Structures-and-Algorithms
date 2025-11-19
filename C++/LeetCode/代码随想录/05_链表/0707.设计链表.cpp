/*
你可以选择使用单链表或者双链表，设计并实现自己的链表。
单链表中的节点应该具备两个属性：val 和 next 。
val 是当前节点的值，next 是指向下一个节点的指针/引用。
如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。
实现 MyLinkedList 类：
MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。
在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。
如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
示例：
输入
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
输出
[null, null, null, null, 2, null, 3]
解释
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
myLinkedList.get(1);              // 返回 2
myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
myLinkedList.get(1);              // 返回 3
*/
#include "ListNode.h"
class MyLinkedList
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(nullptr) {}
    };
    ListNode *dummy;
    int size;
    MyLinkedList()
    {
        dummy = new ListNode(0);
        size = 0;
    }

    int get(int index)
    {
        if (size - 1 < index || index < 0)
            return -1;
        ListNode *cur = dummy->next;
        while (index > 0)
        {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        ListNode *node = new ListNode(val);
        node->next = dummy->next;
        dummy->next = node;
        size++;
    }

    void addAtTail(int val)
    {
        ListNode *node = new ListNode(val);
        ListNode *cur = dummy;
        while (cur && cur->next)
            cur = cur->next;
        cur->next = node;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index < 0)
            index = 0;
        ListNode *node = new ListNode(val);
        ListNode *cur = dummy;
        while (index > 0)
        {
            index--;
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        size++;
    }

    void deleteAtIndex(int index)
    {
        // delete命令指示释放了del_node指针原本所指的那部分内存，
        // 被delete后的指针del_node的值（地址）并非就是NULL，而是随机值。
        // 也就是被delete后，如果不再加上一句del_node=nullptr,del_node会成为乱指的野指针
        // 如果之后的程序不小心使用了del_node，会指向难以预想的内存空间
        if (index >= size || index < 0)
            return;
        ListNode *cur = dummy;
        while (index > 0)
        {
            cur = cur->next;
            index--;
        }
        ListNode *del_node = cur->next;
        cur->next = cur->next->next;
        delete del_node;
        del_node = nullptr;
        size--;
    }
    // 添加析构函数释放链表内存
    ~MyLinkedList()
    {
        ListNode *current = dummy;
        while (current != nullptr)
        {
            ListNode *next = current->next;
            delete current;
            current = next;
        }
        dummy = nullptr;
        size = 0;
    }
};

int main()
{
    return 0;
}