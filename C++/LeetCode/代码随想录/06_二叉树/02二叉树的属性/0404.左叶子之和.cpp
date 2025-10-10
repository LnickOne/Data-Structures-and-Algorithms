/*
给定二叉树的根节点 root ，返回所有左叶子之和。
示例 1：
输入: root = [3,9,20,null,null,15,7]
输出: 24
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
示例 2:
输入: root = [1]
输出: 0
*/
#include "../BinaryTree.h" 
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        return postOrder(root); // 后序遍历,需要收集子树的信息返回给根节点
    }
    int postOrder(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        if (root->left && !root->left->left && !root->left->right) // 如果是左叶子 则它的左孩子和右孩子都为空
            left = root->left->val;                                // 收集左叶子的值
        int mid = left + right;
        return mid;
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    cout << s.sumOfLeftLeaves(root) << endl;
    delete root;
    return 0;
}