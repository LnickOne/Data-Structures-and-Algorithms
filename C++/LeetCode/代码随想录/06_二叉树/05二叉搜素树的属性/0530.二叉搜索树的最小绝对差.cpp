/*
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
差值是一个正数，其数值等于两值之差的绝对值。
示例 1：
输入：root = [4,2,6,1,3]
输出：1
示例 2：
输入：root = [1,0,48,null,null,12,49]
输出：1
*/
#include "../BinaryTree.h"
#include <climits>
class Solution
{
public:
    int result = INT_MAX;
    int diff;
    TreeNode *pre;
    int getMinimumDifference(TreeNode *root)
    {
        inOrder(root);
        return result;
    }
    void inOrder(TreeNode *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        if (pre)
        {
            diff = abs(root->val - pre->val);
            result = min(result, diff);
        }
        pre = root;
        inOrder(root->right);
        return;
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    delete root; // 释放二叉树内存
    return 0;
}