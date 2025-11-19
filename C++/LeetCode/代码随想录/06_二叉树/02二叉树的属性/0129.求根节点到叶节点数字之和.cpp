/*
给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：
例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。
叶节点 是指没有子节点的节点。
示例 1：
输入：root = [1,2,3]
输出：25
解释：
从根到叶子节点路径 1->2 代表数字 12
从根到叶子节点路径 1->3 代表数字 13
因此，数字总和 = 12 + 13 = 25
示例 2：
输入：root = [4,9,0,5,1]
输出：1026
解释：
从根到叶子节点路径 4->9->5 代表数字 495
从根到叶子节点路径 4->9->1 代表数字 491
从根到叶子节点路径 4->0 代表数字 40
因此，数字总和 = 495 + 491 + 40 = 1026
*/
#include "../BinaryTree.h" 
#include <numeric>
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        vector<int> result;
        vector<int> path;
        backtracking(root, path, result);
        int res = accumulate(result.begin(), result.end(), 0);
        return res;
    }
    void backtracking(TreeNode *root, vector<int> &path, vector<int> &result)
    {
        // 前序遍历,中左右
        path.push_back(root->val);       // 中
        if (!root->left && !root->right) // 抵达叶子节点
        {
            string str_num;
            for (int &num : path)
                str_num += to_string(num);
            int num = stoi(str_num);
            result.push_back(num);
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
    int res = Solution().sumNumbers(root);
    cout << res << endl;
    delete root;
    return 0;
}