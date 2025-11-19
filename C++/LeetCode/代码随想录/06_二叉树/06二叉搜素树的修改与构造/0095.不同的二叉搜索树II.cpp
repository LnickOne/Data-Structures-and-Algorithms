/*
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
示例 1：
输入：n = 3
输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
示例 2：
输入：n = 1
输出：[[1]]
*/
#include "../BinaryTree.h"
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return buildTree(1, n);
    }
    vector<TreeNode *> buildTree(int start, int end)
    {
        vector<TreeNode *> result;
        if (start > end)
        {
            result.push_back(nullptr);
            return result;
        }
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> left = buildTree(start, i - 1);
            vector<TreeNode *> right = buildTree(i + 1, end);
            for (auto &left : left)
            {
                for (auto &right : right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<TreeNode *> trees = s.generateTrees(3);
    for (TreeNode *tree : trees)
    {
        delete tree;
    }
    return 0;
}