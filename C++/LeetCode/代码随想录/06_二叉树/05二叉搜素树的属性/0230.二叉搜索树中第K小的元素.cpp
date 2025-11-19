/*
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。
示例 1：
输入：root = [3,1,4,null,2], k = 1
输出：1
示例 2：
输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3
*/
#include "../BinaryTree.h"
#include <climits>
class Solution
{
public:
    int path = 0;
    int result = INT_MAX;
    int kthSmallest(TreeNode *root, int k)
    {
        inOrder(root, k);
        return result;
    }
    void inOrder(TreeNode *root, int k)
    {
        if (!root)
            return;
        inOrder(root->left, k); // 左
        path++;                 // 中
        if (path == k)          // 中
        {
            result = root->val; // 中
            return;
        }
        inOrder(root->right, k); // 右
    }
};

int main()
{
    return 0;
}