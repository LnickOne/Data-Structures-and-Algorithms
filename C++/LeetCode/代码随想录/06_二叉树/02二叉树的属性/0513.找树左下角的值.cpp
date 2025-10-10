/*
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。
 */
#include "../BinaryTree.h"    
#include <climits>
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root) // 方法一：层序遍历
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> queue;
        queue.push(root);
        int result;
        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if (i == 0)
                    result = node->val;
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }
        return result;
    }
    int findBottomLeftValue(TreeNode *root) // 方法二：递归
    {
        backtracking(root, 0);
        return result;
    }
    int maxDepth = INT_MIN;
    int result;
    void backtracking(TreeNode *root, int depth)
    {
        if (!root->left && !root->right) // 叶子节点
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        if (root->left)
        {
            depth++;
            backtracking(root->left, depth);
            depth--; // 回溯
        }
        if (root->right)
        {
            depth++;
            backtracking(root->right, depth);
            depth--; // 回溯
        }
        return;
    }
};