
/*
给定一个二叉树 root ，返回其最大深度。
二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：3
示例 2：
输入：root = [1,null,2]
输出：2
*/
#include "../BinaryTree.h"
#include <deque>
class Solution
{
public:
    // 方法一：后序遍历法
    int maxDepth(TreeNode *root)
    {
        return postOrder(root);
    }
    int postOrder(TreeNode *root) // 左右中，在中节点计算深度
    {
        if (!root)
            return 0;
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        int mid = max(left, right) + 1;
        return mid;
    }
    // 方法二：层序遍历法
    // int maxDepth(TreeNode *root) // 层序遍历法
    // {
    //     if (!root)
    //         return 0;
    //     int depth = 0;
    //     queue<TreeNode *> queue;
    //     vector<int> result;
    //     queue.push(root);
    //     while (!queue.empty())
    //     {
    //         int size = queue.size();
    //         depth +=1;
    //         for (int i = 0; i < size; i++)
    //         {
    //             TreeNode *node = queue.front();
    //             queue.pop();
    //             if (node->left != nullptr)
    //                 queue.push(node->left);
    //             if (node->right != nullptr)
    //                 queue.push(node->right);
    //         }
    //     }
    //     return depth;
    // }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(2);
    root->left = left;
    root->right = right;
    Solution s;
    cout << s.maxDepth(root) << endl;
    return 0;
}
