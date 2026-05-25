/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/pOCWxh/)
题目描述
给定二叉树根节点 root, 树中每个节点的值为 0 或 1。
请剪除该二叉树中所有节点的值为 0 的子树。
题目样例
示例1
- 输入: [1,null,0,0,1]
- 输出: [1,null,0,null,1]
示例2
- 输入: [1,0,1,0,0,0,1]
- 输出: [1,null,1,null,1]
示例3
- 输入: [1,1,0,1,1,0,1,0]
- 输出: [1,1,0,1,1,null,1]
题目思考
1. 如何在得到子树所有节点值的同时进行剪除操作?
解决方案
思路
- DFS: 后序遍历, 先递归判断左右子树是否全为 0
- 若左子树全 0 则断开左连接; 若右子树全 0 则断开右连接
- 当前子树全 0 的条件: 节点值为 0 且左右子树均全为 0
- 用哨兵节点包裹根节点, 避免根节点需要被删时的特殊处理
复杂度
- 时间复杂度 O(N): 遍历每个节点一遍
- 空间复杂度 O(H): H 是树的高度, 递归栈空间
 */
#include "../剑指Offer1/BinaryTree.h"

class Solution
{
    bool allZero(TreeNode *node)
    {
        if (!node) return true;
        bool lz = allZero(node->left);
        bool rz = allZero(node->right);
        if (lz) node->left = nullptr;
        if (rz) node->right = nullptr;
        return node->val == 0 && lz && rz;
    }
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        TreeNode dummy(0);
        dummy.left = root;
        allZero(&dummy);
        return dummy.left;
    }
};

void printBFS(TreeNode *root)
{
    if (!root) { cout << "null" << endl; return; }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front(); q.pop();
        if (node) { cout << node->val << " "; q.push(node->left); q.push(node->right); }
        else cout << "null ";
    }
    cout << endl;
}

int main()
{
    Solution sol;
    auto r1 = createBinaryTree({1, -1, 0, 0, 1});
    printBFS(sol.pruneTree(r1)); // 1 null 0 null 1 ...
    auto r2 = createBinaryTree({1, 0, 1, 0, 0, 0, 1});
    printBFS(sol.pruneTree(r2)); // 1 null 1 null 1 ...
    return 0;
}
