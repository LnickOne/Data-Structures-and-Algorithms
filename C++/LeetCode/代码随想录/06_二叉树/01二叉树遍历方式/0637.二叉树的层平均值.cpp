#include "../BinaryTree.h"
#include <queue>
vector<double> averageOfLevels(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<double> result;
    vector<double> path;
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
            if (node->left)
                queue.push(node->left);
            if (node->right)
                queue.push(node->right);
        }
        double sum = 0;
        for (double num : path)
        {
            sum += num;
        }
        result.push_back(sum / path.size());
        path.clear();
    }
    return result;
}