#include <vector>
#include <iostream>
using namespace std;
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
    TreeNode *deduceTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
            return nullptr;
        TreeNode *root = new TreeNode(preorder.front());
        int root_index;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == preorder.front())
            {
                root_index = i;
                break;
            }
        }
        vector<int> preorder_left;
        vector<int> preorder_right;
        vector<int> inorder_left;
        vector<int> inorder_right;
        inorder_left.assign(inorder.begin(), inorder.begin() + root_index);
        inorder_right.assign(inorder.begin() + root_index + 1, inorder.end());
        preorder_left.assign(preorder.begin() + 1, preorder.begin() + 1 + inorder_left.size());
        preorder_right.assign(preorder.begin() + 1 + inorder_left.size(), preorder.end());
        root->left = deduceTree(preorder_left, inorder_left);
        root->right = deduceTree(preorder_right, inorder_right);
        return root;
    }
};
int main()
{
    Solution s;
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    TreeNode *root = s.deduceTree(preorder, inorder);
    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    cout << root->right->left->val << endl;
    cout << root->right->right->val << endl;
    delete root;
    return 0;
}