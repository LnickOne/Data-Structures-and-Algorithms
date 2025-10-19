#include "ListNode.h"
class Solution
{
public:
    vector<int> list;
    Solution(ListNode *head)
    {
        while (head)
        {
            list.push_back(head->val);
            head = head->next;
        }
    }
    int getRandom()
    {
        return list[rand() % list.size()];
    }
};
