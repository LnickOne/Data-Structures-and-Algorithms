/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/jC7MId/)
题目描述
路径被定义为从树中任意节点出发, 沿父子连接到达任意节点的序列 (同一节点至多出现一次)。
路径和是路径中各节点值之和。给定二叉树根节点 root, 返回最大路径和。
题目样例
示例1
- 输入: root = [1,2,3]
- 输出: 6 (路径: 2->1->3)
示例2
- 输入: root = [-10,9,20,null,null,15,7]
- 输出: 42 (路径: 15->20->7)
题目思考
1. 最大路径和可能有哪些情况?
解决方案
思路
- DFS: 对每个节点计算单向路径最大和 (只能延伸到一侧子树)
- 单向最大和 = max(节点值, 左单向+节点值, 右单向+节点值)
- 在计算过程中更新全局最大值, 同时考虑穿过当前节点 (左+右+节点值) 的路径
- 子树返回单向路径值, 因为父节点无法使用穿过子树的路径
复杂度
- 时间复杂度 O(N): 每个节点只会被遍历一次
- 空间复杂度 O(H): H 是树的高度, 递归栈空间
 */
#include "../剑指Offer1/BinaryTree.h"
#include <climits>

class Solution
{
    int res = INT_MIN;
    int dfs(TreeNode *node)
    {
        if (!node) return INT_MIN / 2;
        int lmx = dfs(node->left);
        int rmx = dfs(node->right);
        int mx = max({node->val, lmx + node->val, rmx + node->val});
        res = max({res, mx, lmx + rmx + node->val});
        return mx;
    }
public:
    int maxPathSum(TreeNode *root)
    {
        res = INT_MIN;
        dfs(root);
        return res;
    }
};

int main()
{
    Solution sol;
    auto r1 = createBinaryTree({1, 2, 3});
    cout << sol.maxPathSum(r1) << endl; // 6
    delete r1;
    auto r2 = createBinaryTree({-10, 9, 20, -1, -1, 15, 7});
    cout << sol.maxPathSum(r2) << endl; // 42
    delete r2;
    auto r3 = createBinaryTree({-3});
    cout << sol.maxPathSum(r3) << endl; // -3
    delete r3;
    return 0;
}
