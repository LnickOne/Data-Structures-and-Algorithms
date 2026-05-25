/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/opLdQZ/)
题目描述
给定二叉搜索树的根节点 root 和整数 k, 判断是否存在两个节点使其值之和等于 k。
题目样例
示例1
- 输入: root = [8,6,10,5,7,9,11], k = 12
- 输出: true (5+7=12)
示例2
- 输入: root = [8,6,10,5,7,9,11], k = 22
- 输出: false
题目思考
1. 如何利用二叉搜索树的性质?
解决方案
思路
- 中序遍历将 BST 转为有序数组, 再用头尾双指针找两数之和等于 k 的数对
复杂度
- 时间复杂度 O(N): 中序遍历 O(N) + 双指针 O(N)
- 空间复杂度 O(N): 额外有序数组存储所有节点的值
 */
#include "BinaryTree.h"
#include <vector>

class Solution
{
    vector<int> nums;
    void inorder(TreeNode *node)
    {
        if (!node) return;
        inorder(node->left);
        nums.push_back(node->val);
        inorder(node->right);
    }
public:
    bool findTarget(TreeNode *root, int k)
    {
        nums.clear();
        inorder(root);
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int sm = nums[i] + nums[j];
            if (sm == k) return true;
            else if (sm < k) i++;
            else j--;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    auto r1 = createBinaryTree({8, 6, 10, 5, 7, 9, 11});
    cout << sol.findTarget(r1, 12) << endl; // true
    cout << sol.findTarget(r1, 22) << endl; // false
    delete r1;
    return 0;
}
