/*
给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]
*/
#include "../BinaryTree.h"    
#include <algorithm>
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> result;
        vector<int> path;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                path.push_back(node->val);
                queue.pop();
                if (node->left != nullptr)
                    queue.push(node->left);
                if (node->right != nullptr)
                    queue.push(node->right);
            }
            result.push_back(path);
            path.clear();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    vector<int> arr = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *root = createBinaryTree(arr);
    Solution s;
    vector<vector<int>> result = s.levelOrderBottom(root);
    for (auto &path : result)
    {
        for (auto &val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    delete root;
    return 0;
}