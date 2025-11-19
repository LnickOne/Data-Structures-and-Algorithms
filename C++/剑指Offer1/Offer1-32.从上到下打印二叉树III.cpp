#include "BinaryTree.h"
#include <algorithm>
class Solution
{
public:
    vector<vector<int>> decorateRecord(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        queue<TreeNode *> queue;
        queue.push(root);
        vector<int> path;
        bool odd = true;
        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                path.push_back(node->val);
                queue.pop();
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            if (odd == false)
            {
                reverse(path.begin(), path.end());
            }
            result.push_back(path);
            path.clear();
            odd = !odd;
        }
        return result;
    }
};