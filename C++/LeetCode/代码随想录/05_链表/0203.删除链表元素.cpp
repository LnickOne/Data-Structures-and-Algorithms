/*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
示例 2：
输入：head = [], val = 1
输出：[]
示例 3：
输入：head = [7,7,7,7], val = 7
输出：[]
*/
#include "ListNode.h"
#include "../../include/ListNode.h"
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 方法一：使用虚拟头节点操作
        if(head == nullptr)
            return nullptr;
        if(head->val == val){
            return head->next;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy; // 有可能需要对头节点操作的时候就需要一个cur指针进行遍历，否则头节点的值不断地改变最后不能返回原来列表的头节点
        while (cur->next)      // cur->next->next== nullptr也可以 就是cur->next==nullptr指向最后了，不需要判断cur->next ->next!= nullptr
        {
            if (cur->next->val == val)
            {
                ListNode* node = cur->next;
                int value = node->val;
                while(node && node->val == value) // 可能连续多个节点的值为val
                {
                    ListNode *del_node = node;
                    node = node->next;
                    delete del_node; // 删除节点释放内存
                    del_node = nullptr;
                }
                cur->next = node; // 把cur->next指向node
            }
            else
                cur = cur->next;
        }
        return dummy->next; // 原来的头节点head有可能已经被删除了,dummy->next有可能是新链表的头节点
        // 方法二：直接在原节点操作
        while (head && head->val == val) // 操作头节点，如果头节点的值为val就一直删除头节点
        {
            ListNode *node = head;
            head = head->next;
            delete node; // 删除节点释放内存
        }
        ListNode *cur = head;
        while (cur && cur->next) // 操作非头部节点
        {
            if (cur->next->val == val)
            {
                ListNode *node = cur->next;
                cur->next = cur->next->next;
                delete node;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
        // 方法三：递归操作
        if (head == nullptr) //  基础情况：空链表
        {
            return nullptr;
        }

        // 递归处理
        if (head->val == val)
        {
            ListNode *newHead = removeElements(head->next, val);
            delete head;
            return newHead;
        }
        else
        {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};

int main()
{
    ListNode *head_1 = createListNode({1, 2, 6, 3, 4, 5, 6});
    ListNode *head_2 = createListNode({7, 7, 7, 7});
    Solution().removeElements(head_1, 6);
    Solution().removeElements(head_2, 7);
    return 0;
}