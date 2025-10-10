#include "../BinaryTree.h"
/*
给你两棵二叉树： root1 和 root2 。
想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。
你需要将这两棵树合并成一棵新二叉树。
合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；
否则，不为 null 的节点将直接作为新二叉树的节点。
返回合并后的二叉树。
注意: 合并过程必须从两个树的根节点开始。
示例 1：
输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
输出：[3,4,5,5,4,null,7]
示例 2：
输入：root1 = [1], root2 = [1,2]
输出：[2,2]
*/
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return postOrder(root1, root2);
    }
    TreeNode *postOrder(TreeNode *root1, TreeNode *root2)
    {
        // 后序遍历
        if (!root1 && !root2)
            return nullptr;
        if (!root1)
            return root2;
        if (!root2)
            return root1;
        TreeNode *left = postOrder(root1->left, root2->left);
        TreeNode *right = postOrder(root1->right, root2->right);
        TreeNode *root = new TreeNode(root1->val + root2->val);
        root->left = left;
        root->right = right;
        return root;
    }
};

int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);

    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);

    Solution s;
    TreeNode *mergedRoot = s.mergeTrees(root1, root2);
    delete mergedRoot;

    return 0;
}