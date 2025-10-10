/*
二叉搜索树是一个有序树：
若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
它的左、右子树也分别为二叉搜索树
这就决定了，二叉搜索树，递归遍历和迭代遍历和普通二叉树都不一样。
*/

/*
给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
你需要在 BST 中找到节点值等于 val 的节点。
返回以该节点为根的子树。
如果节点不存在，则返回 null 。
示例 1:
输入：root = [4,2,7,1,3], val = 2
输出：[2,1,3]
示例 2:
输入：root = [4,2,7,1,3], val = 5
输出：[]
*/
#include "../BinaryTree.h"
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return nullptr;
        return inOrder(root, val);
    }
    TreeNode *inOrder(TreeNode *root, int val)
    {
        if (!root)
            return nullptr;
        if (root->val == val)
            return root;
        if (root->val > val)
        {
            TreeNode *left = inOrder(root->left, val);
            if (left)
                return left;
        }
        if (root->val < val)
        {
            TreeNode *right = inOrder(root->right, val);
            if (right)
                return right;
        }
        return nullptr;
    }
};