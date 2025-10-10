/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
示例 1：
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
*/
#include "../BinaryTree.h" 
class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        // int result = rootSum(root, targetSum);
        // result += pathSum(root->left, targetSum);
        // result += pathSum(root->right, targetSum);
        return preOrder(root, targetSum);
    }
    int rootSum(TreeNode *root, long targetSum)
    {
        if (!root)
            return 0;
        long result = 0;
        if (root->val == targetSum)
            result++;
        result += rootSum(root->left, targetSum - root->val);
        result += rootSum(root->right, targetSum - root->val);
        return result;
    }
    int preOrder(TreeNode *root, int targetSum){
        if(!root)
            return 0;
        int result = 0;
        if(root->val == targetSum)
            result++;
        result += preOrder(root->left, targetSum - root->val);
        result += preOrder(root->right, targetSum - root->val);
        return result;
    }
};

int main()
{
    TreeNode *root = createBinaryTree({10, 5, -3, 3, 2, 11, 3, -2, 1});
    Solution s;
    s.pathSum(root, 8);
}