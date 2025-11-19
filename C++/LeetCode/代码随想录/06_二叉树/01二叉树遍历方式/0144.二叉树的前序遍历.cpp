#include "../BinaryTree.h" 
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        preOrder(root, result);
        return result;
    }
    void preOrder(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
            return;
        result.push_back(root->val);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution s;
    vector<int> result = s.preorderTraversal(root);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    delete root; // 释放二叉树内存
    return 0;
}