/*
给出二叉 搜索 树的根节点，该树的节点值各不相同，
请你将其转换为累加树（Greater pre_val Tree），
使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
示例 1：
输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
示例 2：
输入：root = [0,null,1]
输出：[1,null,1]
示例 3：
输入：root = [1,0,2]
输出：[3,3,2]
示例 4：
输入：root = [3,2,4,1]
输出：[7,9,4,10]
*/
#include "../BinaryTree.h"
class Solution
{
public:
    int pre_val;
    TreeNode *convertBST(TreeNode *root)
    {
        return reverseInOrder(root);
    }

    TreeNode *reverseInOrder(TreeNode *root)
    {
        // 题目要求从大到小 所以按照二叉搜索树的特点倒序一下 右中左
        if (!root)
            return nullptr;
        TreeNode *right = reverseInOrder(root->right);
        pre_val += root->val;
        root->val = pre_val;
        TreeNode *left = reverseInOrder(root->left);
        root->right = right;
        root->left = left;
        return root;
    }
};