/*
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点。
示例 1：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
解释：等于目标和的根节点到叶节点路径如上图所示。
*/
#include "../BinaryTree.h" 
#include <numeric>
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        vector<bool> result;
        vector<int> path;
        backtracking(root, targetSum, path, result);
        for (bool res : result)
            if (res == true)
                return true;
        return false;
    }
    void backtracking(TreeNode *&root, const int &targetSum, vector<int> &path, vector<bool> &result)
    {
        path.push_back(root->val);       // 前序遍历,中左右
        if (!root->left && !root->right) // 当节点左右都为空时候表明到底则收集一个路径
        {
            int sum = accumulate(path.begin(), path.end(), 0);
            if (sum == targetSum)
                result.push_back(true);
            return;
        }
        if (root->left)
        {
            backtracking(root->left, targetSum, path, result);
            path.pop_back();
        }
        if (root->right)
        {
            backtracking(root->right, targetSum, path, result);
            path.pop_back();
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);
    cout << Solution().hasPathSum(root, 22) << endl;
    delete root;
    return 0;
}