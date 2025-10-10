#include "../BinaryTree.h" 
#include <iostream>
#include <algorithm>

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // 前序遍历中左右和后序遍历左右中都可以，中序遍历不符合要求，因为中序遍历是左中右，所以不能交换左右节点
        if (!root)
            return nullptr;
        postOrder(root);
        return root;
    }
    void postOrder(TreeNode *root) // 后序遍历
    {
        if (!root)
            return;
        postOrder(root->left);
        postOrder(root->right);
        swap(root->left, root->right);
        return;
    }
    // 自己写轮子
    //  void swap(TreeNode *root)
    //  {
    //      TreeNode *temp = root->left;
    //      root->left = root->right;
    //      root->right = temp;
    //  }
};