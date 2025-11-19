/*
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
叶子节点 是指没有子节点的节点。
示例 1：
输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]
示例 2：
输入：root = [1]
输出：["1"]
*/
#include "../BinaryTree.h" 
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<string> result;
        vector<int> path;
        backtracking(root, path, result);
        return result;
    }
    void backtracking(TreeNode *root, vector<int> &path, vector<string> &result)
    {
        // 前序遍历,中左右
        path.push_back(root->val);       // 中
        if (!root->left && !root->right) // 抵达根节点的判断条件 即左右两边都为空
        {
            string path_str;
            for (int i = 0; i < path.size(); i++)
            {
                path_str += to_string(path[i]);
                if (i != path.size() - 1)
                {
                    path_str += "->";
                }
            }
            result.push_back(path_str); // 收集一个路径
        }
        if (root->left) // 左
        {
            backtracking(root->left, path, result);
            path.pop_back();
        }
        if (root->right) // 右
        {
            backtracking(root->right, path, result);
            path.pop_back();
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    Solution s;
    vector<string> result = s.binaryTreePaths(root);
    for (auto str : result)
        cout << str << endl;
    delete root;
    return 0;
}