#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。如下图所示
输入描述：
二叉树的根节点
返回值描述：
双向链表的其中一个头节点。
输入：
{10,6,14,4,8,12,16}
返回值：
From left to right are:4,6,8,10,12,14,16;From right to left are:16,14,12,10,8,6,4;
输入：
{5,4,#,3,#,2,#,1}
返回值：
From left to right are:1,2,3,4,5;From right to left are:5,4,3,2,1;
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        this->val = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{
public:
    TreeNode *pre = nullptr;
    TreeNode *head = nullptr;
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (pRootOfTree == nullptr)
            return nullptr;
        Convert(pRootOfTree->left);
        if (pre == nullptr)
        {
            head = pRootOfTree;
            pre = pRootOfTree;
        }
        else
        {
            pre->right = pRootOfTree;
            pRootOfTree->left = pre;
            pre = pRootOfTree;
        }
        Convert(pRootOfTree->right);
        return head;
    }
};

int main()
{
    return 0;
}