#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createListNode(const vector<int> &arr)
{
    if (arr.empty()) return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;
    for (int i = 1; i < (int)arr.size(); ++i)
    {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printListNode(ListNode *head)
{
    bool first = true;
    while (head) { if (!first) cout << "->"; cout << head->val; first = false; head = head->next; }
    cout << endl;
}

void deleteList(ListNode *head)
{
    while (head) { ListNode *t = head; head = head->next; delete t; }
}
