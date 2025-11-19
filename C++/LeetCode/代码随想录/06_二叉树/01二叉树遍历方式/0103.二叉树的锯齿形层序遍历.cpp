/*
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。
（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[20,9],[15,7]]
示例 2：
输入：root = [1]
输出：[[1]]
示例 3：
输入：root = []
输出：[]
*/
#include "../BinaryTree.h"
#include <algorithm>
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
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
                queue.pop();
                path.push_back(node->val);
                if (node->left != nullptr)
                    queue.push(node->left);
                if (node->right != nullptr)
                    queue.push(node->right);
            }
            result.push_back(path);
            path.clear();
        }
        for (int i = 0; i < result.size(); i++)
            if (i % 2 == 1)
                reverse(result[i].begin(), result[i].end());
        return result;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;

    vector<vector<int>> result = s.zigzagLevelOrder(root);
    for (auto &path : result)
    {
        for (auto &val : path)
            cout << val << " ";
        cout << endl;
    }
    delete root;
    return 0;
}