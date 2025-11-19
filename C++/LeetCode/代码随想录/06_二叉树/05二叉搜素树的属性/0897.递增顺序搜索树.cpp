/*
给你一棵二叉搜索树的 root ，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，
使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
示例 1：
输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
示例 2：
输入：root = [5,1,7]
输出：[1,null,5,null,7]
*/
#include "../BinaryTree.h"
class Solution
{
public:
    TreeNode *pre;
    TreeNode *newRoot;
    TreeNode *increasingBST(TreeNode *root)
    {
        if (!root)
            return nullptr;
        inOrder(root);
        return newRoot;
    }
    void inOrder(TreeNode *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        if (!newRoot)
        {
            newRoot = root;
            pre = root;
        }
        else
        {
            pre->right = root; // 将前一个节点的右子节点指向当前节点
            pre = root;
        }
        root->left = nullptr; // 清空当前节点的左子节点
        inOrder(root->right);
        pre->right = nullptr; // 处理最后一个节点的右子节点
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    Solution s;
    TreeNode *newRoot = s.increasingBST(root);
    delete newRoot;
    return 0;
}