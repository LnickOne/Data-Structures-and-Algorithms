/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/6eUYwP/)
题目描述
给定二叉树根节点 root 和整数 targetSum, 求路径和等于 targetSum 的路径数目。
路径不需要从根节点开始或在叶节点结束, 但方向必须向下。
题目样例
示例1
- 输入: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
- 输出: 3
示例2
- 输入: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
- 输出: 3
题目思考
1. 如何快速计算任意路径的和?
2. 如何快速得到指定和的路径数目?
解决方案
思路
- 递归 + 前缀和计数字典 (类似数组中和为 k 的子数组)
- DFS 时维护从根到当前节点的前缀和 curSum, 以及 unordered_map<long long,int> 记录前缀和出现次数
- 以当前节点为终点且路径和为 targetSum 的路径数 = sumCnt[curSum - targetSum]
- 进入子树前将 curSum 加入 map, 返回后减回 (恢复现场)
- 初始化 sumCnt[0] = 1 表示空路径
复杂度
- 时间复杂度 O(N): 每个节点只会被遍历一次
- 空间复杂度 O(N): 递归栈和前缀和字典
 */
#include "../剑指Offer1/BinaryTree.h"
#include <unordered_map>

class Solution
{
    int res = 0;
    unordered_map<long long, int> sumCnt;
    void dfs(TreeNode *node, long long curSum, long long target)
    {
        curSum += node->val;
        res += sumCnt.count(curSum - target) ? sumCnt[curSum - target] : 0;
        sumCnt[curSum]++;
        if (node->left) dfs(node->left, curSum, target);
        if (node->right) dfs(node->right, curSum, target);
        sumCnt[curSum]--;
    }
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        res = 0;
        sumCnt.clear();
        sumCnt[0] = 1;
        if (root) dfs(root, 0, (long long)targetSum);
        return res;
    }
};

int main()
{
    Solution sol;
    auto r1 = createBinaryTree({10, 5, -3, 3, 2, -1, 11, 3, -2, -1, 1});
    cout << sol.pathSum(r1, 8) << endl; // 3
    delete r1;
    auto r2 = createBinaryTree({5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, -1, 5, 1});
    cout << sol.pathSum(r2, 22) << endl; // 3
    delete r2;
    return 0;
}
