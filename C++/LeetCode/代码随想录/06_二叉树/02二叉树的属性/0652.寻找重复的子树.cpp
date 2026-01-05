/*
给你一棵二叉树的根节点 root ，返回所有 重复的子树 。
对于同一类的重复子树，你只需要返回其中任意 一棵 的根结点即可。
如果两棵树具有 相同的结构 和 相同的结点值 ，则认为二者是 重复 的。
示例 1：
输入：root = [1,2,3,4,null,2,4,null,null,4]
输出：[[2,4],[4]]
示例 2：
输入：root = [2,1,1]
输出：[[1]]
示例 3：
输入：root = [2,2,2,3,null,3,null]
输出：[[2,3],[3]]
*/
#include "../BinaryTree.h"
#include <unordered_map>
class Solution
{
public:
    vector<TreeNode *> result;
    unordered_map<string, int> map;
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        if (!root)
            return {};
        postOrder(root);
        return result;
    }

    string postOrder(TreeNode *root)
    {
        if (!root)
            return "#";
        // 递归序列化左右子树
        string left = postOrder(root->left);
        string right = postOrder(root->right);
        // 构建当前子树的序列化字符串
        string subTree = to_string(root->val) + "," + left + "," + right;
        // 记录子树出现次数
        map[subTree]++;
        // 当子树出现次数为 2 时，添加到结果中
        if (map[subTree] == 2)
            result.push_back(root);
        return subTree;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution s;
    vector<TreeNode *> result = s.findDuplicateSubtrees(root);
    for (auto node : result)
        cout << node->val << endl;
    return 0;
}