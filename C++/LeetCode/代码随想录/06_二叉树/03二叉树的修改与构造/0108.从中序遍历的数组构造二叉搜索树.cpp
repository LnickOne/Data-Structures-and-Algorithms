#include "../BinaryTree.h" 

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) { return bulidBST(nums); }
    TreeNode *bulidBST(vector<int> nums)
    {
        if (nums.empty())
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
        nums_right.assign(nums.begin() + nums_left.size() + 1, nums.end());
        root->left = bulidBST(nums_left);
        root->right = bulidBST(nums_right);
        return root;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution s;
    TreeNode *root = s.sortedArrayToBST(nums);
    delete root;
    return 0;
}