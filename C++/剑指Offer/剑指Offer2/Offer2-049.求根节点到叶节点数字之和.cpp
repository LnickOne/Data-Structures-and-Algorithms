/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/3Etpl5/)
题目描述
给定二叉树根节点 root, 每个节点存放 0-9 的数字。
每条根到叶节点的路径代表一个数字 (如 1->2->3 代表 123)。
计算所有根到叶节点路径数字之和。
题目样例
示例1
- 输入: root = [1,2,3]
- 输出: 25 (12+13)
示例2
- 输入: root = [4,9,0,5,1]
- 输出: 1026 (495+491+40)
题目思考
1. 如何快速计算每条路径的数字和?
解决方案
思路
- 自顶向下 DFS, 传入当前节点和从根到当前节点的路径数字 num
- 到达每个节点时: num = 父节点 num * 10 + 当前节点值
- 到达叶节点时将 num 累加到结果
复杂度
- 时间复杂度 O(N): 每个节点只需遍历一次
- 空间复杂度 O(H): H 是树深度, 递归栈空间
 */
#include "../剑指Offer1/BinaryTree.h"

class Solution
{
    int res = 0;
    void dfs(TreeNode *node, int num)
    {
        num = num * 10 + node->val;
        if (!node->left && !node->right) { res += num; return; }
        if (node->left) dfs(node->left, num);
        if (node->right) dfs(node->right, num);
    }
public:
    int sumNumbers(TreeNode *root)
    {
        res = 0;
        if (root) dfs(root, 0);
        return res;
    }
};

int main()
{
    Solution sol;
    auto r1 = createBinaryTree({1, 2, 3});
    cout << sol.sumNumbers(r1) << endl; // 25
    delete r1;
    auto r2 = createBinaryTree({4, 9, 0, 5, 1});
    cout << sol.sumNumbers(r2) << endl; // 1026
    delete r2;
    return 0;
}
