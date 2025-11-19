#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
/*
给定一个二叉树，确定他是否是一个完全二叉树。
完全二叉树的定义：若二叉树的深度为 h，除第 h 层外，
其它各层的结点数都达到最大个数，第 h 层所有的叶子结点都连续集中在最左边，这就是完全二叉树。
（第 h 层可能包含 [1~2h] 个节点）
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        /*
        思路：
        完全二叉树只会在最后一层出现null,而且出现一次null后不会再出现非空值
        因此通过层序遍历记录第一次null，如果后面又出现一次非空值，表示左节点为空，右节点不为空，则为非完全二叉树
        */
        if (root == nullptr)
            return true;
        queue<TreeNode *> queue;
        queue.push(root);
        bool null_node = false;
        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if (node == nullptr)
                    null_node = true;
                if (node != nullptr)
                {
                    queue.push(node->left);
                    queue.push(node->right);
                    if (null_node == true)
                        return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}