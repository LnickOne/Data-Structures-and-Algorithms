/*
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
若最底层为第 h 层（从第 0 层开始），则该层包含 1~ 2h 个节点。
示例 1：
输入：root = [1,2,3,4,5,6]
输出：6
示例 2：
输入：root = []
输出：0
示例 3：
输入：root = [1]
输出：1
*/
#include "../BinaryTree.h" 
class Solution
{
public:
    int countNodes(TreeNode *root)// 层序遍历
    { 
        if (root == nullptr)
            return 0;
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
                result.push_back(node->val);
                if (node->left != nullptr)
                    queue.push(node->left);
                if (node->right != nullptr)
                    queue.push(node->right);
            }
        }
        return result.size();
    }

    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftnum= countNodes(root->left);
        int rightnum = countNodes(root->right);
        return leftnum + rightnum + 1;
    }
};