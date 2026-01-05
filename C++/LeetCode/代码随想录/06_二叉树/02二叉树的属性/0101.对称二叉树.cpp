/*
给你一个二叉树的根节点 root ， 检查它是否轴对称。
示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false
*/
#include "../BinaryTree.h"
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return postOrder(root->left, root->right);
    }
    bool postOrder(TreeNode *left, TreeNode *right)
    {
        // 对称二叉树比较的是两个子树的里侧和外侧的元素是否相等，边界条件判断如下：
        // 左    右
        // 空    空
        // 空    不空
        // 不空  空
        // 值 ≠  值
        if (!left && right)
            return false;
        if (left && !right)
            return false;
        if (!left && !right)
            return true;
        if (left->val != right->val)
            return false;
        // 此时：左右节点都不为空，且数值相同的情况才做递归，做下一层的判断,左右中 后序遍历
        bool outside = postOrder(left->left, right->right); // 左子树：左、 右子树：右
        bool inside = postOrder(left->right, right->left);  // 左子树：右、 右子树：左
        bool mid = outside && inside;                       // 左子树：中、 右子树：中（逻辑处理）
        return mid;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(2);
    root->left = left;
    root->right = right;
    Solution s;
    cout << s.isSymmetric(root) << endl;
    return 0;
}
