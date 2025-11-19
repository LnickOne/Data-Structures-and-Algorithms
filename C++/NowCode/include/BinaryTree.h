#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode // 树结构体
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    queue<TreeNode *> queue;
    TreeNode *root = new TreeNode(arr[0]);
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < arr.size())
    {
        TreeNode *node = queue.front();
        queue.pop();
        if (i < arr.size() && arr[i] != -1)
        {
            node->left = new TreeNode(arr[i]);
            queue.push(node->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1)
        {
            node->right = new TreeNode(arr[i]);
            queue.push(node->right);
        }
        i++;
    }
    return root;
}
