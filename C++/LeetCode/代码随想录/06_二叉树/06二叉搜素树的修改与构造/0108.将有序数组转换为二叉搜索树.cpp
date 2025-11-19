/*
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵平衡二叉搜索树。
示例 1：
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
示例 2：
输入：nums = [1,3]
输出：[3,1]
解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
*/
#include "../BinaryTree.h"
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        // 方法一
        if (nums.size() == 0)
            return nullptr;
        int root_index;
        if (nums.size() % 2 == 0)
            root_index = nums.size() / 2 - 1;
        if (nums.size() % 2 == 1)
            root_index = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[root_index]);
        vector<int> nums_left;
        vector<int> nums_right;
        nums_left.assign(nums.begin(), nums.begin() + root_index);
        nums_right.assign(nums.begin() + root_index + 1, nums.end());
        root->left = sortedArrayToBST(nums_left);
        root->right = sortedArrayToBST(nums_right);
        return root;
        // 方法二
        // return buildBST(nums, 0, nums.size() - 1);
    }

    TreeNode *buildBST(int left, int right, vector<int> &nums)
    {
        if (left > right) // 当left>right时候为非法区间
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildBST(left, mid - 1, nums);
        root->right = buildBST(mid + 1, right, nums);
        return root;
    }
};

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution s;
    TreeNode *root = s.sortedArrayToBST(nums);
    delete root;
    return 0;
}