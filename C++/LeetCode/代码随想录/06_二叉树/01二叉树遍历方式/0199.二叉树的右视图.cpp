/*
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
*/
#include "../BinaryTree.h"    
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> result;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if (i == size - 1) // 每一层的最后一个节点
                    result.push_back(node->val);
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }
        return result;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    Solution().rightSideView(root);
    delete root; // 释放二叉树内存
    return 0;
}