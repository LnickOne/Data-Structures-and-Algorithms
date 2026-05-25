#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *createBinaryTree(const vector<int> &vec)
{
    if (vec.empty()) return nullptr;
    TreeNode *root = new TreeNode(vec[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)vec.size())
    {
        TreeNode *node = q.front(); q.pop();
        if (i < (int)vec.size() && vec[i] != -1)
        {
            node->left = new TreeNode(vec[i]);
            q.push(node->left);
        }
        ++i;
        if (i < (int)vec.size() && vec[i] != -1)
        {
            node->right = new TreeNode(vec[i]);
            q.push(node->right);
        }
        ++i;
    }
    return root;
}
