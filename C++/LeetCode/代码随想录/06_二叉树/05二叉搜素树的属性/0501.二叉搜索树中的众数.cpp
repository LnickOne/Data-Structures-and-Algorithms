/*
给你一个含重复值的二叉搜索树（BST）的根节点 root ，
找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
如果树中有不止一个众数，可以按 任意顺序 返回。
假定 BST 满足如下定义：
结点左子树中所含节点的值 小于等于 当前节点的值
结点右子树中所含节点的值 大于等于 当前节点的值
左子树和右子树都是二叉搜索树
示例 1：
输入：root = [1,null,2,2]
输出：[2]
示例 2：
输入：root = [0]
输出：[0]
*/
#include "../BinaryTree.h"
#include <unordered_map>
class Solution
{
public:
    // 方法一
    vector<int> findMode(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> result;
        unordered_map<int, int> map;
        int max_frequency = 0;
        inOrder(root, map);
        for (auto iter = map.begin(); iter != map.end(); iter++)
        {
            if (iter->second > max_frequency)
            {
                max_frequency = iter->second;
                result.clear();
                result.push_back(iter->first);
            }
            else if (iter->second == max_frequency)
                result.push_back(iter->first);
        }

        return result;
    }

    void inOrder(TreeNode *root, unordered_map<int, int> &map)
    {
        if (!root)
            return;
        inOrder(root->left, map);
        map[root->val]++;
        inOrder(root->right, map);
    }

    // 方法二
    vector<int> result;
    int max_frequency = 0;
    int cur_frequency = 0;
    TreeNode *pre = nullptr;
    vector<int> findMode(TreeNode *root)
    {
        if (root == nullptr)
            return result;
        findMode(root->left);
        if (pre == nullptr)
            cur_frequency = 1;
        else if (pre->val == root->val)
            cur_frequency++;
        else if (pre->val != root->val)
            cur_frequency = 1;
        pre = root;                         // 更新上一个节点
        if (cur_frequency == max_frequency) // 收获结果
            result.push_back(root->val);
        if (cur_frequency > max_frequency)
        {
            max_frequency = cur_frequency;
            result.clear();
            result.push_back(root->val);
        }
        findMode(root->right);
        return result;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    Solution s;
    vector<int> result = s.findMode(root);
    for (auto i : result)
        cout << i << " ";
    delete root; // 释放二叉树内存
    return 0;
}