/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/w6cpku/)
题目描述
给定二叉搜索树, 将每个节点的值替换成树中大于或等于该节点值的所有节点值之和。
题目样例
示例1
- 输入: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
- 输出: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
示例2
- 输入: root = [0,null,1]
- 输出: [1,null,1]
示例3
- 输入: root = [1,0,2]
- 输出: [3,3,2]
题目思考
1. 如何利用二叉搜索树的性质?
解决方案
思路
- 逆向中序遍历 (右->根->左) 即从大到小遍历 BST
- 维护后缀和 sm, 遍历每个节点时将其值累加到 sm, 再将节点值更新为 sm
复杂度
- 时间复杂度 O(N): 遍历每个节点一次
- 空间复杂度 O(H): H 是树的高度, 递归栈空间
 */
#include "BinaryTree.h"

class Solution
{
    int sm = 0;
    void revInorder(TreeNode *node)
    {
        if (!node) return;
        revInorder(node->right);
        sm += node->val;
        node->val = sm;
        revInorder(node->left);
    }
public:
    TreeNode *convertBST(TreeNode *root)
    {
        sm = 0;
        revInorder(root);
        return root;
    }
};

int main()
{
    Solution sol;
    auto r1 = createBinaryTree({4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8});
    sol.convertBST(r1);
    // BFS 打印验证
    queue<TreeNode *> q;
    q.push(r1);
    while (!q.empty())
    {
        auto node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl; // 30 36 21 36 35 26 15 33 8
    delete r1;
    auto r2 = createBinaryTree({1, 0, 2});
    sol.convertBST(r2);
    cout << r2->val << " " << r2->left->val << " " << r2->right->val << endl; // 3 3 2
    delete r2;
    return 0;
}
