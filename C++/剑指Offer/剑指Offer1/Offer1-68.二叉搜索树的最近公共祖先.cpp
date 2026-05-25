#include "BinaryTree.h"
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val > p->val && root->val > q->val)
        {
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            if (left != nullptr)
                return left;
        }
        if (root->val < p->val && root->val < q->val)
        {
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            if (right != nullptr)
                return right;
        }
        return root;
    }
};
int main()
{
    // BST: [6,2,8,0,4,7,9,null,null,3,5], p=2, q=8 => 6
    TreeNode *root = createBinaryTree({6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5});
    TreeNode *p = root->left;  // 2
    TreeNode *q = root->right; // 8
    Solution s;
    cout << s.lowestCommonAncestor(root, p, q)->val << endl; // 6
    // p=2, q=4 => 2
    TreeNode *q2 = root->left->right;                         // 4
    cout << s.lowestCommonAncestor(root, p, q2)->val << endl; // 2
    return 0;
}
