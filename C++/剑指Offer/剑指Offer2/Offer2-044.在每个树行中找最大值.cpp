/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/hPov7L/)
题目描述
给定二叉树的根节点 root, 请找出该二叉树中每一层的最大值。
题目样例
示例1
- 输入: root = [1,3,2,5,3,null,9]
- 输出: [1,3,9]
示例2
- 输入: root = [1,2,3]
- 输出: [1,3]
示例3
- 输入: root = []
- 输出: []
题目思考
1. 如何记录当前层的信息?
解决方案
思路
- 按层 BFS: 每次记录当前层节点数 sz, 遍历这 sz 个节点统计最大值
- 将左右非空子节点加入队列, 下一轮循环处理下一层
复杂度
- 时间复杂度 O(N): 遍历每个节点一遍
- 空间复杂度 O(N): 队列存储各层节点
 */
#include "../剑指Offer1/BinaryTree.h"
#include <vector>
#include <climits>

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size(), mx = INT_MIN;
            for (int i = 0; i < sz; i++)
            {
                auto node = q.front(); q.pop();
                mx = max(mx, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(mx);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    auto print = [](vector<int> &v) { for (int x : v) cout << x << " "; cout << endl; };
    auto r1 = createBinaryTree({1, 3, 2, 5, 3, -1, 9});
    auto res1 = sol.largestValues(r1);
    print(res1); // 1 3 9
    delete r1;
    auto r2 = createBinaryTree({1, 2, 3});
    auto res2 = sol.largestValues(r2);
    print(res2); // 1 3
    delete r2;
    auto res3 = sol.largestValues(nullptr);
    print(res3); // (空)
    return 0;
}
