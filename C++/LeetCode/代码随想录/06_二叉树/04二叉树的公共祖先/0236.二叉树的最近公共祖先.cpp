
/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，
最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
示例 1：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
示例 2：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
示例 3：
输入：root = [1,2], p = 1, q = 2
输出：1
*/
#include "../BinaryTree.h"
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return postOrder(root, p, q);
    }
    TreeNode *postOrder(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return nullptr;
        if (root == p)
            return p;
        if (root == q)
            return q;
        TreeNode *left = postOrder(root->left, p, q);
        TreeNode *right = postOrder(root->right, p, q);
        // 处理当前根节点：在完成左子树和右子树的递归处理后，才开始处理当前根节点。根据左右子树的返回结果，判断最近公共祖先节点：
        // 若 left 为空，说明 p 和 q 不在左子树中，返回 right。
        // 若 right 为空，说明 p 和 q 不在右子树中，返回 left。
        // 若 left 和 right 都不为空，说明 p 和 q 分别在左右子树中，当前节点就是最近公共祖先，返回 root。
        if (left== nullptr)
            return right;
        if (right== nullptr)
            return left;
        if (left && right)
            return root;
        return root;
    }
};