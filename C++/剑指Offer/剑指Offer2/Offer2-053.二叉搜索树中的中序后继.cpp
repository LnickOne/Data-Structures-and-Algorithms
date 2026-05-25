/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/P5rCT8/)
题目描述
给定二叉搜索树和其中一个节点 p, 找到该节点的中序后继 (比 p.val 大的最小节点)。
若没有中序后继则返回 null。
题目样例
示例1
- 输入: root = [2,1,3], p = 1
- 输出: 2
示例2
- 输入: root = [5,3,6,2,4,null,null,1], p = 6
- 输出: null
题目思考
1. 如何利用二叉搜索树的性质?
解决方案
思路
- 利用 BST 性质进行二分查找: 当前节点大于 p 时向左子树查找, 否则向右子树查找
- 当当前节点大于 p 且小于已知的最近后继 (res) 时更新 res
复杂度
- 时间复杂度 O(logN): 二分查找
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include "../剑指Offer1/BinaryTree.h"

class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *res = nullptr;
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->val > p->val)
            {
                if (!res || cur->val < res->val) res = cur;
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    // 示例1: [2,1,3] p=1 -> 2
    TreeNode *r1 = createBinaryTree({2, 1, 3});
    TreeNode *p1 = r1->left; // 节点 1
    TreeNode *ans1 = sol.inorderSuccessor(r1, p1);
    cout << (ans1 ? ans1->val : -1) << endl; // 2
    delete r1;
    // 示例2: [5,3,6,2,4,-1,-1,1] p=6 -> null
    TreeNode *r2 = createBinaryTree({5, 3, 6, 2, 4, -1, -1, 1});
    TreeNode *p2 = r2->right; // 节点 6
    TreeNode *ans2 = sol.inorderSuccessor(r2, p2);
    cout << (ans2 ? ans2->val : -1) << endl; // -1
    delete r2;
    return 0;
}
