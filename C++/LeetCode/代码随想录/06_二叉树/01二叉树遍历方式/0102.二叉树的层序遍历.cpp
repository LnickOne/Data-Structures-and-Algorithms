#include "../BinaryTree.h"
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
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
    vector<vector<int>> result = s.levelOrder(root);
    for (auto &path : result)
    {
        for (auto &val : path)
            cout << val << " ";
        cout << endl;
    }
    delete root; // 释放二叉树内存
    return 0;
}