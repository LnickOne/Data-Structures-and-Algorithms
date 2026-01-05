/*
给定一个二叉树，判断它是否是 平衡二叉树
如果一棵二叉树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：true
示例 2：
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
示例 3：
输入：root = []
输出：true
*/
#include "../BinaryTree.h"
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return postOrder(root) == -1 ? false : true;
    }
    int postOrder(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        int mid = max(left, right) + 1;
        if (left == -1)
            return -1;
        if (right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        return mid;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(2);
    root->left = left;
    root->right = right;
    Solution s;
    cout << s.isBalanced(root) << endl;
    return 0;
}
