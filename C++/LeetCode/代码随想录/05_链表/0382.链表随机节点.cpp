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
int main()
{
    ListNode *head_1 = createListNode({1, 2, 3, 4, 5});
    Solution solution(head_1);
    int result = solution.getRandom();
    std::cout << result << std::endl;
    return 0;
}
