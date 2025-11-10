/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
示例 1:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
*/
#include "../BinaryTree.h"
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return postOrder(root, p, q); // 用后序遍历，也可以找到p和q的最近公共祖先，但是需要判断p和q是否在左子树和右子树中
        return inOrder(root, p, q);   // 用中序遍历，因为二叉搜索树的中序遍历是有序的，所以可以判断p和q的大小关系，
    }

    TreeNode *postOrder(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        if (root == p)
            return p;
        if (root == q)
            return q;
        TreeNode *left = postOrder(root->left, p, q);
        TreeNode *right = postOrder(root->right, p, q);
        if (!left) // 若 left 为空，说明 p 和 q 不在左子树中，返回 right。
            return right;
        if (!right) // 若 right 为空，说明 p 和 q 不在右子树中，返回 left。
            return left;
        if (left && right) // 若 left 和 right 都不为空，说明 p 和 q 分别在左右子树中，当前节点就是最近公共祖先，返回 root。
            return root;
        return root;
        // 处理当前根节点：在完成左子树和右子树的递归处理后，才开始处理当前根节点。
        // 根据左右子树的返回结果，判断最近公共祖先节点：
    }
    TreeNode *inOrder(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        if (root == p)
            return p;
        if (root == q)
            return q;
        if (root->val > p->val && root->val > q->val) // 如果根的值大于p和q的值，说明p和q都在左子树中，所以递归左子树
        {
            TreeNode *left = inOrder(root->left, p, q);
            return left;
        }
        cout << root->val << endl;
        if (root->val < p->val && root->val < q->val) // 如果根的值小于p和q的值，说明p和q都在右子树中，所以递归右子树
        {
            TreeNode *right = inOrder(root->right, p, q);
            return right;
        }
        return root;
    }
};
int main()
{
    Solution s;
    // 构建二叉搜索树
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    TreeNode *p = new TreeNode(2);
    TreeNode *q = new TreeNode(8);
    TreeNode *ancestor = s.lowestCommonAncestor(root, p, q);
    delete root;
    delete p;
    delete q;
    return 0;
}