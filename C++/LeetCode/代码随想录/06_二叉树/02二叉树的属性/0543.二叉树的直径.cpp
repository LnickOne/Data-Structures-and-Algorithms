/*
给你一棵二叉树的根节点，返回该树的 直径 。
二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。
这条路径可能经过也可能不经过根节点 root 。
两节点之间路径的 长度 由它们之间边数表示。
示例 1：
输入：root = [1,2,3,4,5]
输出：3
解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
示例 2：
输入：root = [1,2]
输出：1
*/
#include "../BinaryTree.h" 
class Solution
{
public:
    int result = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        postOrder(root);
        return result;
    }
    int postOrder(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        int mid = max(left, right) + 1;
        result = max(result, left + right); // 更新最大直径 ，即 左子树最大深度+右子树最大深度
        return mid;                         // 返回节点深度
    }
};