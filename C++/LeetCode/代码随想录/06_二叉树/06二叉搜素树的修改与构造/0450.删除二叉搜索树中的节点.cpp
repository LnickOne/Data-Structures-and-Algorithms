/*
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
返回二叉搜索树（有可能被更新）的根节点的引用。
一般来说，删除节点可分为两个步骤：
首先找到需要删除的节点；
如果找到了，删除它。
示例 1:
输入：root = [5,3,6,2,4,null,7], key = 3
输出：[5,4,6,2,null,null,7]
解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
另一个正确答案是 [5,2,6,null,4,null,7]。
示例 2:
输入: root = [5,3,6,2,4,null,7], key = 0
输出: [5,3,6,2,4,null,7]
解释: 二叉树不包含值为 0 的节点
示例 3:
输入: root = [], key = 0
输出: []
*/
#include "../BinaryTree.h"
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    { // 有五种情况
        if (root == nullptr)
            return root; // 没找到删除节点
        if (root->val == key)
        {
            if (root->left == nullptr && root->right == nullptr) // 左空右空
            {
                delete root;
                return nullptr;
            }

            if (root->left == nullptr) // 左空右不空
            {
                TreeNode *new_node = root->right;
                delete root;
                return new_node;
            }
            if (root->right == nullptr) // 左不空右空
            {
                TreeNode *new_node = root->left;
                delete root;
                return new_node;
            }
            TreeNode *node = root->right; // 左不空右不空
            while (node->left != nullptr)
                node = node->left;
            node->left = root->left;
            TreeNode *old_node = root; // 把root节点保存一下，下面来删除
            delete old_node;           // 释放节点内存
            return root->right;
        }
        if (root->val < key) // 往左寻找
            root->right = deleteNode(root->right, key);
        if (root->val > key) // 往右寻找
            root->left = deleteNode(root->left, key);
        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    // ... 构建二叉树 ...
    Solution solution;
    TreeNode *newRoot = solution.deleteNode(root, 3);
    // 递归释放二叉树内存
    std::queue<TreeNode *> q;
    if (newRoot)
        q.push(newRoot);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
        delete node;
    }
    return 0;
}