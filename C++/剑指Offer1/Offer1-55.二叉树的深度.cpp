#include "BinaryTree.h"
class Solution
{
public:
    int calculateDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = calculateDepth(root->left);
        int right = calculateDepth(root->right);
        int depth = max(left, right) + 1;
        return depth;
    }
};