#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    // 构造函数
    // TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
    // 析构函数
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

TreeNode *createBinaryTree(const vector<int> &arr) // 创建二叉树
{
    if (arr.empty())
        return nullptr;
    queue<TreeNode *> nodes;
    TreeNode *root = new TreeNode(arr[0]);
    nodes.push(root);
    int i = 1;
    while (!nodes.empty() && i < arr.size())
    {
        TreeNode *current = nodes.front();
        nodes.pop();
        if (i < arr.size() && arr[i] != -1)
        {
            current->left = new TreeNode(arr[i]);
            nodes.push(current->left);
        }
        i += 1;
        if (i < arr.size() && arr[i] != -1)
        {
            current->right = new TreeNode(arr[i]);
            nodes.push(current->right);
        }
        i += 1;
    }
    return root;
}
