#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
小偷又发现了一个新的可行窃的地区。
这个地区只有一个入口，我们称之为 root 。
除了 root 之外，每栋房子有且只有一个“父“房子与之相连。
一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
示例 1:
输入: root = [3,2,3,null,3,null,1]
输出: 7
解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
示例 2:
输入: root = [3,4,5,1,3,null,1]
输出: 9
解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int rob(TreeNode *root)
    {
        // 长度为2的数组，状态0：不偷，状态1：偷。
        // 每次递归系统栈都会保存每次递归里的参数，因此每一层都有长度为2的dp数组
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
    vector<int> robTree(TreeNode *root)
    {                        // 后序遍历 左右中
        if (root == nullptr) // 遇到空节点 偷和不偷最大金币都为0
            return vector<int>{0, 0};
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        int val_0 = max(left[0], left[1]) + max(right[0], right[1]); // 不偷当前节点，那么左右节点都可以考虑偷或者不偷，取最大值的情况
        int val_1 = root->val + left[0] + right[0];                  // 偷当前节点，那么就不能偷左右节点,所以左右的值都为数组的0号元素。
        return {val_0, val_1};
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    Solution s;
    cout << s.rob(root) << endl;
    return 0;
}
