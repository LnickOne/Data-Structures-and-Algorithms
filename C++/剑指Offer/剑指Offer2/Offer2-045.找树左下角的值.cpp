/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/LwUNpT/)
题目描述
给定二叉树的根节点 root, 找出该二叉树最底层最左边节点的值。
假设二叉树中至少有一个节点。
题目样例
示例1
- 输入: root = [2,1,3]
- 输出: 1
示例2
- 输入: root = [1,2,3,4,null,5,6,null,null,7]
- 输出: 7
题目思考
1. 如何找出最底层?
解决方案
思路
- 按层 BFS: 每层遍历时记录该层第一个节点的值为 res
- 遍历结束后 res 就是最底层最左侧节点的值
复杂度
- 时间复杂度 O(N): 遍历每个节点一遍
- 空间复杂度 O(N): 队列存储各层节点
 */
#include "../剑指Offer1/BinaryTree.h"

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int res = root->val;
        while (!q.empty())
        {
            int sz = q.size();
            res = q.front()->val;
            for (int i = 0; i < sz; i++)
            {
                auto node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    auto r1 = createBinaryTree({2, 1, 3});
    cout << sol.findBottomLeftValue(r1) << endl; // 1
    delete r1;
    auto r2 = createBinaryTree({1, 2, 3, 4, -1, 5, 6, -1, -1, 7});
    cout << sol.findBottomLeftValue(r2) << endl; // 7
    delete r2;
    return 0;
}
