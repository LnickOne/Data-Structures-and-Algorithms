/*
给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。
如果有多种构造方法，请你返回任意一种。
如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。
示例 1：
输入：root = [1,null,2,null,3,null,4,null,null]
输出：[2,1,3,null,null,null,4]
解释：这不是唯一的正确答案，[3,1,4,null,2,null,null] 也是一个可行的构造方案。
示例 2：
输入: root = [2,1,3]
输出: [2,1,3]
*/
#include "../BinaryTree.h"
class Solution
{
public:
    TreeNode *balanceBST(TreeNode *root)
    {
        // 构建平衡二叉树
        vector<int> nums; // 用数组存储中序遍历的结果
        inOrder(root, nums);
        return buildTree(nums, 0, nums.size() - 1); // 构建平衡二叉树
    }
    void inOrder(TreeNode *root, vector<int> &nums) // 中序遍历
    {
        if (!root)
            return;
        inOrder(root->left, nums);  // 左
        nums.push_back(root->val);  // 中
        inOrder(root->right, nums); // 右
    }
    TreeNode *buildTree(vector<int> &nums, int left, int right) // 用中序遍历的数组构建平衡二叉树
    {
        if (left > right) // 如果左指针大于右指针，返回nullptr
            return nullptr;
        int mid = left + (right - left) / 2;           // 找到中间节点
        TreeNode *root = new TreeNode(nums[mid]);      // 创建根节点
        root->left = buildTree(nums, left, mid - 1);   // 构建左子树
        root->right = buildTree(nums, mid + 1, right); // 构建右子树
        return root;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    Solution s;
    TreeNode *balancedRoot = s.balanceBST(root);
    delete root;
    delete balancedRoot;
    return 0;
}