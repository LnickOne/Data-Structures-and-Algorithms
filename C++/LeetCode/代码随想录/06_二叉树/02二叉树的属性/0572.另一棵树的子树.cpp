/*
给你两棵二叉树 root 和 subRoot 。
检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。
如果存在，返回 true ；否则，返回 false 。
二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。
tree 也可以看做它自身的一棵子树。
 */
#include "../BinaryTree.h" 
class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;
        // 这里细节：根部比较是全部比较 所以直接去递归isSameTree(root, subRoot)
        // 左子树和右子树比较是部分比较，所以要递归的是isSubtree(root->left, subRoot)，而不是isSameTree(root->left, subRoot)
        bool mid = isSameTree(root, subRoot);
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return mid || left || right;
    }

    bool isSameTree(TreeNode *left, TreeNode *right)
    {
        // 因为要不断收集左右孩子的信息返回给上一个节点，使用后序遍历
        // 比较的是两个树是否相等
        // 空    空
        // 空    不空
        // 不空  空
        // 值 ≠  值
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr && right != nullptr)
            return false;
        if (left != nullptr && right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        // 此时：左右节点都不为空并且数值相同，继续做递归，做下一层的判断,左右中的后序遍历
        bool left = isSameTree(left->left, right->left);
        bool right = isSameTree(left->right, right->right);
        bool mid = left && right;
        return mid; // 左子树：中、 右子树：中 （逻辑处理）
    }
};