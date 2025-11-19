#include "../BinaryTree.h"

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return postOrder(p, q);
    }
    bool postOrder(TreeNode *p, TreeNode *q)
    {
        // 相同的树比较的是两个子树的左右树是否相等
        // 边界条件判断如下：后序遍历 左右中
        // 空    空    true
        // 空    不空   false
        // 不空  空    false
        // 值 ≠  值    false
        if (!p && !q)
            return true;
        if (!p && q)
            return false;
        if (p && !q)
            return false;
        if (p->val != q->val)
            return false;
        bool left = postOrder(p->left, q->left);
        bool right = postOrder(p->right, q->right);
        bool mid = left && right;
        return mid;
    }
};
int main()
{
    TreeNode *p = new TreeNode(1);
    TreeNode *q = new TreeNode(1);
    Solution s;
    cout << s.isSameTree(p, q) << endl;
    return 0;
}