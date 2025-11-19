#include <queue>
#include <vector>
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<int> solve(vector<int> &preOrder, vector<int> &inOrder)
    {
        TreeNode *root = buildTree(preOrder, inOrder);
        if (root == nullptr)
            return {};
        vector<int> result;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if (i == size - 1)
                    result.push_back(node->val);
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }
        return result;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (inorder.size() == 0 || preorder.size() == 0)
            return nullptr;
        int root_val = preorder.front();
        TreeNode *root = new TreeNode(root_val);
        if (preorder.size() == 1)
            return root;
        int root_index;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == root_val)
            {
                root_index = i;
                break;
            }
        }
        vector<int> inorder_left;
        vector<int> inorder_right;
        vector<int> preorder_left;
        vector<int> preorder_right;
        inorder_left.assign(inorder.begin(), inorder.begin() + root_index);
        inorder_right.assign(inorder.begin() + root_index + 1, inorder.end());
        preorder_left.assign(preorder.begin() + 1, preorder.begin() + 1 + inorder_left.size());
        preorder_right.assign(preorder.begin() + 1 + inorder_left.size(), preorder.end());
        root->left = buildTree(preorder_left, inorder_left);
        root->right = buildTree(preorder_right, inorder_right);
        return root;
    }
};

int main()
{
    vector<int> preOrder = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> inOrder = {4, 7, 2, 1, 5, 3, 8, 6};
    Solution solution;
    auto result = solution.solve(preOrder, inOrder);
    for (auto i : result)
        cout << i << " ";
    return 0;
}