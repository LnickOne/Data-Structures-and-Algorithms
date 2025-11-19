#include "BinaryTree.h"
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return depth(root) == -1 ? false : true;
    }
    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        int diff_depth = abs(left - right);
        if (left == -1)
            return -1;
        if (right == -1)
            return -1;
        if (diff_depth > 1)
            return -1;
        return max(left, right) + 1;
    }
};