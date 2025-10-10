/*
给定两个整数数组 inorder 和 postorder ，
其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
示例 1:
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]
示例 2:
输入：inorder = [-1], postorder = [-1]
输出：[-1]
 */
#include "../BinaryTree.h" 
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.empty() || postorder.empty())
            return nullptr;
        int root_val = postorder.back();
        TreeNode *root = new TreeNode(root_val);
        int root_index;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == root_val)
            {
                root_index = i;
                break;
            }
        }
        vector<int> inorder_left(inorder.begin(), inorder.begin() + root_index);
        vector<int> inorder_right;
        vector<int> postorder_left;
        vector<int> postorder_right;
        //inorder_left.assign(inorder.begin(), inorder.begin() + root_index);
        inorder_right.assign(inorder.begin() + root_index + 1, inorder.end());
        postorder_left.assign(postorder.begin(), postorder.begin() + inorder_left.size());
        postorder_right.assign(postorder.begin() + inorder_left.size(), postorder.end() - 1);
        root->left = buildTree(inorder_left, postorder_left);
        root->right = buildTree(inorder_right, postorder_right);
        return root;
    }
};

int main()
{

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    Solution solution;
    TreeNode *binary_tree = solution.buildTree(inorder, postorder);
    delete binary_tree;
    return 0;
}