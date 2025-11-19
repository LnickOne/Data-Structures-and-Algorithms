/*
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：2
示例 2：
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
*/
#include "../BinaryTree.h" 
class Solution
{
public:
    // 方法一 层序遍历法
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int depth = 0;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            depth++;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if (node->left == nullptr && node->right == nullptr) // 当左右孩子都为空的时候，说明是最低点的一层了，退出
                    return depth;
                if (node->left != nullptr)
                    queue.push(node->left);
                if (node->right != nullptr)
                    queue.push(node->right);
            }
        }
        return depth;
    }
    // 方法二 后序遍历
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int result = postOrder(root);
        return result;
    }
    int postOrder(TreeNode *root) // 后序遍历
    {
        if (!root)
            return 0;
        int left = postOrder(root->left);   // 左
        int right = postOrder(root->right); // 右
        int mid = min(left, right) + 1;     // 中
        if (!root->left)                    // 当一个左子树为空，右子树不为空，这时并不是最低点
            return right + 1;
        if (!root->right) // 当一个右子树为空，左子树不为空，这时并不是最低点
            return left + 1;
        return mid;
    }
};