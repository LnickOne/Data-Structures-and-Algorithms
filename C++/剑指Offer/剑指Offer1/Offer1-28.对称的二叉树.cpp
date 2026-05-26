/*
题目难度: 简单
 > [原题链接](https://leetcode.cn/problems/dui-cheng-de-er-cha-shu-lcof/description/)
题目描述
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3
0 <= 节点个数 <= 1000
题目样例
示例 1
输入
root = [1,2,2,3,4,4,3]
输出
true
示例 2
输入
root = [1,2,2,null,3,null,3]
输出
false
题目思考
生成镜像比较可以吗, 直接比较呢?
如果限制只能用递归或者迭代, 如何解决?
解决方案
方案 1
思路
根据题目描述, 最自然的思路就是生成原树的镜像后, 再逐个节点比较是否完全相等即可
对于生成镜像部分不清楚的同学可以回顾下上篇文章 剑指 Offer 27. 二叉树的镜像 - leetcode 剑指offer系列
需要注意这里生成的镜像不能直接在原树基础上改动了, 需要生成新的节点, 也即新建一个节点使用原来的节点值, 不然下面比较的时候就是和自身比较, 肯定总是相等了
逐个节点比较也很简单, 如果其中某个节点为空, 则必须另一个也是空; 而如果两个节点都非空的话, 则要比较它们的值, 并传入左右子节点递归比较子树的相等性
复杂度
时间复杂度 O(N)
所有节点只需要遍历一遍
空间复杂度 O(N)
递归栈的消耗, 以及镜像树的空间
*/
#include "BinaryTree.h"
class Solution
{
public:
    bool checkSymmetricTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return compare(root->left, root->right);
    }
    bool compare(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr && right != nullptr)
            return false;
        if (left != nullptr && right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        bool left_result = compare(left->right, right->left);
        bool right_result = compare(left->left, right->right);
        return left_result && right_result;
    }
};
int main()
{
    TreeNode *root = createBinaryTree({1, 2, 2, 3, 4, 4, 3});
    Solution s;
    bool result = s.checkSymmetricTree(root);
    cout << result << endl;
    return 0;
}