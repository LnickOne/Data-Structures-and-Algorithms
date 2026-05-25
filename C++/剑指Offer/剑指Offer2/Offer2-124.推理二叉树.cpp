/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/)
题目描述
给定不含重复数字的前序遍历 preorder 和中序遍历 inorder, 重建二叉树并返回根节点。
题目样例
示例1
- 输入: preorder=[3,9,20,15,7], inorder=[9,3,15,20,7]
- 输出: [3,9,20,null,null,15,7]
示例2
- 输入: preorder=[-1], inorder=[-1]
- 输出: [-1]
题目思考
1. 如何利用前序和中序遍历的性质?
解决方案
思路
- 前序首元素为根; 在中序中找到根位置 im, 划分左右子树
- 用 unordered_map 存值到中序下标的映射, O(1) 查询
- 递归分治建树
复杂度
- 时间复杂度 O(N): 每个节点只访问一次
- 空间复杂度 O(N): 字典和递归栈
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include "BinaryTree.h"
using namespace std;

class Solution
{
    vector<int> pre;
    unordered_map<int, int> inIdx;
    TreeNode *build(int pb, int pe, int ib, int ie)
    {
        if (pb > pe) return nullptr;
        TreeNode *root = new TreeNode(pre[pb]);
        int im = inIdx[pre[pb]];
        int pm = pb + im - ib;
        root->left = build(pb + 1, pm, ib, im - 1);
        root->right = build(pm + 1, pe, im + 1, ie);
        return root;
    }
public:
    TreeNode *deduceTree(vector<int> &preorder, vector<int> &inorder)
    {
        pre = preorder;
        int n = (int)preorder.size();
        for (int i = 0; i < n; ++i) inIdx[inorder[i]] = i;
        return build(0, n - 1, 0, n - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> pre1 = {3, 9, 20, 15, 7}, in1 = {9, 3, 15, 20, 7};
    TreeNode *r1 = sol.deduceTree(pre1, in1);
    // 前序验证: 3 9 20 15 7
    cout << r1->val << " " << r1->left->val << " " << r1->right->val
         << " " << r1->right->left->val << " " << r1->right->right->val << endl; // 3 9 20 15 7
    vector<int> pre2 = {-1}, in2 = {-1};
    TreeNode *r2 = sol.deduceTree(pre2, in2);
    cout << r2->val << endl; // -1
    return 0;
}
