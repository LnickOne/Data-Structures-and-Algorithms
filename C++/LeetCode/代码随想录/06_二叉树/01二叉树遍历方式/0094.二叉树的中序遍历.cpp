#include "../BinaryTree.h"
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inOrder(root, result);
        return result;
    }
    void inOrder(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution solution;
    vector<int> result = solution.inorderTraversal(root);
    for (auto &i : result)
        cout << i << " ";
    cout << endl;
    delete root;
    return 0;
}