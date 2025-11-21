/*
二叉搜索树是一个有序树：
若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
它的左、右子树也分别为二叉搜索树
这就决定了，二叉搜索树，递归遍历和迭代遍历和普通二叉树都不一样。
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
示例 1：
输入：root = [2,1,3]
输出：true
示例 2：
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。
*/
#include "../BinaryTree.h"
#include <climits>
using namespace std;
class Solution
{
public:
    // 方法一
    long max_val = LONG_MIN;
    bool isValidBST(TreeNode *root)
    {
        return inOrder(root);
    }
    bool inOrder(TreeNode *root)
    {
        // 二叉搜索树都用中序遍历，因为中序遍历是从小到大排序的
        //  所以可以判断当前节点的值是否大于前一个节点的值，如果大于，说明是二叉搜索树，否则不是
        if (!root)
            return true;
        bool left = inOrder(root->left); // 左
        if (root->val > max_val)         // 中
            max_val = root->val;
        else if (root->val <= max_val)
            return false;
        bool right = inOrder(root->right); // 右
        return left && right;
    }
    // 方法二
    TreeNode *pre = nullptr; // 用来记录前一个节点
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        bool left = isValidBST(root->left); // 左
        if (pre && pre->val >= root->val)   // 中
            return false;
        pre = root;                           // 记录前一个节点
        bool right = isValidBST(root->right); // 右
        return left && right;
    }
};

int main()
{
}