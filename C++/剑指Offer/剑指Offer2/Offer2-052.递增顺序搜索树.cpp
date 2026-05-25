/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/NYBBNL/)
题目描述
给定一棵二叉搜索树, 按中序遍历重新排列为一棵递增顺序搜索树:
树中最左边的节点成为根节点, 每个节点没有左子节点, 只有一个右子节点。
题目样例
示例1
- 输入: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
- 输出: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
示例2
- 输入: root = [5,1,7]
- 输出: [1,null,5,null,7]
题目思考
1. 如何降低时间和空间复杂度?
解决方案
思路
- 中序遍历 BST (左->根->右), 遍历时将前一节点的右子节点指向当前节点, 并将当前节点的左子节点置空
- 引入哨兵节点作为第一个"前一节点", 最终返回哨兵的右子节点
复杂度
- 时间复杂度 O(N): 每个节点只会被遍历一次
- 空间复杂度 O(H): H 是树的高度, 递归栈空间
 */
#include "../剑指Offer1/BinaryTree.h"

class Solution
{
    TreeNode *pre;
    void inorder(TreeNode *node)
    {
        if (!node) return;
        inorder(node->left);
        node->left = nullptr;
        pre->right = node;
        pre = node;
        inorder(node->right);
    }
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode dummy(0);
        pre = &dummy;
        inorder(root);
        return dummy.right;
    }
};

int main()
{
    Solution sol;
    // 示例2: [5,1,7] -> [1,null,5,null,7]
    TreeNode *r1 = createBinaryTree({5, 1, 7});
    TreeNode *res1 = sol.increasingBST(r1);
    for (TreeNode *p = res1; p; p = p->right)
        cout << p->val << " ";
    cout << endl; // 1 5 7
    // 注意 createBinaryTree 的节点已被重排, 需手动清理
    for (TreeNode *p = res1, *nx; p; p = nx) { nx = p->right; p->right = nullptr; delete p; }
    return 0;
}
