#include "../BinaryTree.h" 

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        postOrder(root, result);
        return result;
    }
    void postOrder(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
            return;
        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->val);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution s;
    vector<int> result = s.postorderTraversal(root);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    delete root; // 释放二叉树内存
    return 0;
}