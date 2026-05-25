/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/WNC0Lk/)
题目描述
给定二叉树的根节点 root, 返回从右侧看到的节点值 (每层最右边的节点)。
题目样例
示例1
- 输入: root = [1,2,3,null,5,null,4]
- 输出: [1,3,4]
示例2
- 输入: root = [1,null,3]
- 输出: [1,3]
示例3
- 输入: root = []
- 输出: []
题目思考
1. 如何找出最底层?
解决方案
思路
- 按层 BFS: 每层遍历结束前记录该层最后一个节点的值加入结果
- 返回所有层最右节点值的列表
复杂度
- 时间复杂度 O(N): 遍历每个节点一遍
- 空间复杂度 O(N): 队列存储各层节点
 */
#include "BinaryTree.h"
#include <vector>

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto node = q.front(); q.pop();
                if (i == sz - 1) res.push_back(node->val);
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
    auto print = [](vector<int> &v) { for (int x : v) cout << x << " "; cout << endl; };
    auto r1 = createBinaryTree({1, 2, 3, -1, 5, -1, 4});
    auto res1 = sol.rightSideView(r1);
    print(res1); // 1 3 4
    delete r1;
    auto r2 = createBinaryTree({1, -1, 3});
    auto res2 = sol.rightSideView(r2);
    print(res2); // 1 3
    delete r2;
    auto res3 = sol.rightSideView(nullptr);
    print(res3); // (空)
    return 0;
}
